#cmake_minimum_required (VERSION 2.6)
add_idl(TestCrashIDL TestCrash.idl ${TEST_IDL_DIRECTORY})

set(proj "TestCrashServer")

add_executable(${proj}
Application.cpp
)

target_link_libraries(${proj} CORBACommons TestCrashIDL CORBAConfigParser
    )
add_test(NAME ${proj}
         COMMAND ${proj})

