#ifndef GENERICS_UNCOPYABLE_HPP
#define GENERICS_UNCOPYABLE_HPP

namespace Generics
{
  /**
   * Private inheritance of this class makes impossible the usage of
   * the implicit copy constructor and the assignment operator of the
   * derived class
   */
  class Uncopyable
  {
  protected:
    constexpr
    Uncopyable() = default;
    ~Uncopyable() = default;

    Uncopyable(Uncopyable&) = delete;
    Uncopyable(const Uncopyable&) = delete;
    Uncopyable(Uncopyable&&) = delete;
    Uncopyable(const Uncopyable&&) = delete;
    void
    operator =(Uncopyable&) = delete;
    void
    operator =(const Uncopyable&) = delete;
    void
    operator =(Uncopyable&&) = delete;
    void
    operator =(const Uncopyable&&) = delete;
  };
}

#endif
