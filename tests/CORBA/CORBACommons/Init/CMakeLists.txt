#cmake_minimum_required (VERSION 2.6)
#add_idl(CORBAInfResolveClientIDL client.idl)

set(proj "CORBACombined")

add_executable(${proj}
Combined.cpp
)

target_link_libraries(${proj} CORBACommons  CORBAConfigParser TestIntIDL
# CORBAInfResolveClientIDL
    )
add_test(NAME ${proj}
         COMMAND ${proj})

