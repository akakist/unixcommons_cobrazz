#cmake_minimum_required (VERSION 2.6)


#include_directories(   /usr/include/apr-1       )

set(proj "CORBACrashCallClient")

add_executable(${proj}
Application.cpp
)



target_link_libraries(${proj} Generics Logger Geoip)


add_test(NAME ${proj}
         COMMAND ${proj})
