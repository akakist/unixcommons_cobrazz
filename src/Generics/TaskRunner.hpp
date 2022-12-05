#ifndef GENERICS_TASK_RUNNER_HPP
#define GENERICS_TASK_RUNNER_HPP

#include <Sync/Semaphore.hpp>

#include <ReferenceCounting/Deque.hpp>

#include <Generics/AtomicInt.hpp>
#include <Generics/Scheduler.hpp>


namespace Generics
{
  /**
   * General Task to be processed by TaskRunner.
   */
  class Task : public virtual ReferenceCounting::Interface
  {
  public:
    /**
     * Method is called by TaskRunner when the object's order arrives.
     */
    virtual
    void
    execute() /*throw (eh::Exception)*/ = 0;

  protected:
    virtual
    ~Task() throw ();
  };

  typedef ReferenceCounting::QualPtr<Task> Task_var;

  struct TaskExecutor :
    public virtual ReferenceCounting::Interface,
    public virtual ActiveObject
  {
    DECLARE_EXCEPTION(Exception, ActiveObject::Exception);
    DECLARE_EXCEPTION(Overflow, Exception);
    DECLARE_EXCEPTION(NotActive, Exception);

    virtual void
    enqueue_task(Task* task, const Time* timeout = 0)
      /*throw (InvalidArgument, Overflow, NotActive, eh::Exception)*/ = 0;
  };

  typedef ReferenceCounting::QualPtr<TaskExecutor> TaskExecutor_var;
  typedef ReferenceCounting::FixedPtr<TaskExecutor> FixedTaskExecutor_var;

  /**
   * Performs tasks in several threads simultaneously.
   */
  class TaskRunner :
    public TaskExecutor,
    public ActiveObjectCommonImpl
  {
  public:
    typedef TaskExecutor::Exception Exception;
    typedef TaskExecutor::Overflow Overflow;
    typedef TaskExecutor::NotActive NotActive;
    typedef ActiveObject::InvalidArgument InvalidArgument;

    /**
     * Constructor
     * @param callback not null callback is called on errors
     * @param threads_number number of working threads
     * @param stack_size their stack sizes
     * @param max_pending_tasks maximum task queue length
     * @param start_threads initial number of threads to start (0 - all)
     */
    TaskRunner(ActiveObjectCallback* callback,
      unsigned threads_number, size_t stack_size = 0,
      unsigned max_pending_tasks = 0,
      unsigned start_threads = 0)
      /*throw (InvalidArgument, Exception, eh::Exception)*/;

    virtual
    void
    activate_object()
      /*throw (AlreadyActive, Exception, eh::Exception)*/;

    /**
     * Enqueues a task
     * @param task task to enqueue. Number of references is not increased
     * @param timeout maximal absolute wait time before fail on mutex lock
     * until the task is put in the queue. NULL timeout means no wait.
     * If you put limitations on the size of the queue, and it's full,
     * method waits for the release up to timeout
     */
    virtual void
    enqueue_task(Task* task, const Time* timeout = 0)
      /*throw (InvalidArgument, Overflow, NotActive, eh::Exception)*/;

    /**
     * Returns number of tasks recently being enqueued
     * This number does not have much meaning in MT environment
     * @return number of tasks enqueued
     */
    unsigned
    task_count() const throw ();

    /**
     * Waits for the moment task queue is empty and returns control.
     * In MT environment tasks can be added at the very same moment of
     * return of control.
     */
    void
    wait_for_queue_exhausting() /*throw (eh::Exception)*/;

    /**
     * Clear task queue
     */
    virtual
    void
    clear() /*throw (eh::Exception)*/;

  protected:
    virtual
    ~TaskRunner() throw ();

  private:
    class TaskRunnerJob : public SingleJob
    {
    public:
      TaskRunnerJob(
        ActiveObjectCallback* callback,
        unsigned number_of_threads,
        unsigned max_pending_tasks,
        unsigned start_threads)
        /*throw (eh::Exception)*/;

      virtual
      void
      work() throw ();

      virtual
      void
      started(unsigned threads) throw ();

      virtual
      void
      terminate() throw ();

      void
      enqueue_task(Task* task, const Time* timeout,
        ThreadRunner& thread_runner)
        /*throw (InvalidArgument, Overflow, NotActive, eh::Exception)*/;

      unsigned
      task_count() const throw ();

      void
      wait_for_queue_exhausting() /*throw (eh::Exception)*/;

      void
      clear() /*throw (eh::Exception)*/;

    protected:
      virtual
      ~TaskRunnerJob() throw ();

      void
      add_thread_i_(ThreadRunner& thread_runner) throw ();

    private:
      typedef ReferenceCounting::Deque<Task_var> Tasks;

      const unsigned NUMBER_OF_THREADS_;
      const unsigned int MAX_PENDING_TASKS_;

      mutable Sync::PosixMutex tasks_lock_;
      unsigned int number_of_unused_threads_;
      unsigned int waiting_threads_; // number of threads, that wait task appearance
      Tasks tasks_;

      Sync::Conditional new_task_;
      Sync::Conditional not_full_;

      // protect
      Generics::AtomicInt adding_thread_;
    };

    typedef ReferenceCounting::FixedPtr<TaskRunnerJob> TaskRunnerJob_var;

    TaskRunnerJob& job_;
  };
  typedef ReferenceCounting::QualPtr<TaskRunner> TaskRunner_var;
  typedef ReferenceCounting::FixedPtr<TaskRunner> FixedTaskRunner_var;

  /**
   * Task with specified RC implementation
   */
  class TaskImpl :
    public virtual Task,
    public virtual ReferenceCounting::AtomicImpl
  {
  protected:
    /**
     * Destructor
     */
    virtual
    ~TaskImpl() throw ();
  };

  /**
   * Should be put into the Planner.
   * When time arrives, it puts itself into TaskRunner.
   */
  class TaskGoal :
    public Goal,
    public Task,
    public ReferenceCounting::AtomicImpl
  {
  public:
    /**
     * Constructor
     * @param task_runner TaskExecutor to put the object into.
     */
    explicit
    TaskGoal(TaskExecutor* task_executor) /*throw (eh::Exception)*/;

    /**
     * Implementation of Goal::deliver.
     * Puts the object into the TaskRunner.
     */
    virtual
    void
    deliver() /*throw (eh::Exception)*/;

  protected:
    /**
     * Destructor
     */
    virtual
    ~TaskGoal() throw ();

  private:
    TaskExecutor_var task_executor_;
  };

  /**
   * Reusable version of TaskGoal
   */
  class GoalTask :
    public Goal,
    public Task,
    public ReferenceCounting::AtomicImpl
  {
  public:
    /**
     * Constructor
     * After the object construction call deliver() to put the object into the
     * TaskExecutor or schedule_() to put it into the Planner.
     * @param planner Planner to put the object into.
     * @param task_runner TaskExecutor to put the object into.
     * or in Planner otherwise
     */
    GoalTask(Planner* planner, TaskExecutor* task_executor)
      /*throw (eh::Exception)*/;

    /**
     * Implementation of Goal::deliver.
     * Puts the object into the TaskExecutor.
     */
    virtual
    void
    deliver() /*throw (eh::Exception)*/;

    /**
     * Put the object into the Planner. Call this in execute().
     * @param time time of putting the object into the TaskRunner
     */
    void
    schedule(const Time& time) /*throw (eh::Exception)*/;

  protected:
    /**
     * Destructor
     */
    virtual
    ~GoalTask() throw ();

  private:
    Planner_var planner_;
    TaskExecutor_var task_executor_;
  };
}

///////////////////////////////////////////////////////////////////////////////
// Inlines
///////////////////////////////////////////////////////////////////////////////

namespace Generics
{
  //
  // Task class
  //

  inline
  Task::~Task() throw ()
  {
  }


  //
  // TaskImpl class
  //

  inline
  TaskImpl::~TaskImpl() throw ()
  {
  }


  //
  // TaskGoal class
  //

  inline
  TaskGoal::TaskGoal(TaskExecutor* task_executor)
    /*throw (eh::Exception)*/
    : task_executor_(ReferenceCounting::add_ref(task_executor))
  {
  }

  inline
  TaskGoal::~TaskGoal() throw ()
  {
  }

  inline
  void
  TaskGoal::deliver() /*throw (eh::Exception)*/
  {
    task_executor_->enqueue_task(this);
  }


  //
  // GoalTask class
  //

  inline
  GoalTask::GoalTask(Planner* planner, TaskExecutor* task_executor)
    /*throw (eh::Exception)*/
    : planner_(ReferenceCounting::add_ref(planner)),
      task_executor_(ReferenceCounting::add_ref(task_executor))
  {
  }

  inline
  GoalTask::~GoalTask() throw ()
  {
  }

  inline
  void
  GoalTask::deliver() /*throw (eh::Exception)*/
  {
    task_executor_->enqueue_task(this);
  }

  inline
  void
  GoalTask::schedule(const Time& when) /*throw (eh::Exception)*/
  {
    planner_->schedule(this, when);
  }


  //
  // TaskRunner::TaskRunnerJob class
  //

  inline
  unsigned
  TaskRunner::TaskRunnerJob::task_count() const throw ()
  {
    Sync::PosixGuard guard(tasks_lock_);
    return tasks_.size();
  }


  //
  // TaskRunner class
  //

  inline
  void
  TaskRunner::enqueue_task(Task* task, const Time* timeout)
    /*throw (InvalidArgument, Overflow, NotActive, eh::Exception)*/
  {
    job_.enqueue_task(task, timeout, thread_runner_);
  }

  inline
  unsigned
  TaskRunner::task_count() const throw ()
  {
    return job_.task_count();
  }

  inline
  void
  TaskRunner::wait_for_queue_exhausting() /*throw (eh::Exception)*/
  {
    job_.wait_for_queue_exhausting();
  }

  inline
  void
  TaskRunner::clear() /*throw (eh::Exception)*/
  {
    job_.clear();
  }
}

#endif
