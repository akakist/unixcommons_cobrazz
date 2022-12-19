#cmake_minimum_required (VERSION 2.6)

set(proj "CORBAOverloadServer")

add_idl(TestIntIDL TestInt.idl  ${TEST_IDL_DIRECTORY})

include_directories(${IDL_DIRECTORY})
add_executable(${proj}
Application.cpp
TestIntImpl.cpp
)

target_link_libraries(${proj} CORBACommons TestCrashIDL CORBAConfigParser TestIntIDL TestCommons2 TestCommons

#StatsIDL
    )
add_test(NAME ${proj}
         COMMAND ${proj})

