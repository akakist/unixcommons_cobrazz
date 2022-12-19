#cmake_minimum_required (VERSION 2.6)
add_idl(CORBAInfResolveClientIDL client.idl  ${TEST_IDL_DIRECTORY})

set(proj "CORBAInfResolveClient")

add_executable(${proj}
TestClient.cpp
)

target_link_libraries(${proj} CORBACommons  CORBAConfigParser CORBAInfResolveClientIDL
    )
add_test(NAME ${proj}
         COMMAND ${proj})

