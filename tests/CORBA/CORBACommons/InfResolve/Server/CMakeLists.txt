#cmake_minimum_required (VERSION 2.6)
add_idl(CORBAInfResolveServerIDL server.idl  ${TEST_IDL_DIRECTORY})

set(proj "CORBAInfResolveServer")

add_executable(${proj}
TestServer.cpp
)

target_link_libraries(${proj} CORBACommons  CORBAConfigParser CORBAInfResolveServerIDL
    )
add_test(NAME ${proj}
         COMMAND ${proj})

