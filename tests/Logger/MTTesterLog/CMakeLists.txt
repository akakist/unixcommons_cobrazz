
set(proj "MTTesterExceptionsLog")

add_executable(${proj}
MTTesterLoggerTest.cpp

  

)


target_link_libraries(${proj} Generics Logger TestCommons2)


