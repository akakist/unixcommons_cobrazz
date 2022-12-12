#cmake_minimum_required (VERSION 2.6)


#include_directories(   /usr/include/apr-1       )


add_library(HTTP  SHARED
  Http.cpp 
  HttpAsync.cpp 
  HttpAsyncPool.cpp 
  HttpAsyncPolicies.cpp 
  HttpClient.cpp 
  HttpConnection.cpp 
  HTTPCookie.cpp 
  HttpSync.cpp 
  UrlAddress.cpp 

)
#add_library(ApacheModule  SHARED
#Module.cpp

#)
#add_library(PreloadACE  SHARED
#PreloadACE.cpp
#)

#link_directories()



target_link_libraries(HTTP Generics Stream event)


