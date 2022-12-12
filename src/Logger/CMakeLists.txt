#cmake_minimum_required (VERSION 2.6)


#include_directories(   /usr/include/apr-1       )


add_library(Logger  SHARED
  ActiveObjectCallback.cpp 
  DescriptorLogger.cpp 
  DistributorLogger.cpp 
  FileLogger.cpp 
  Logger.cpp 
  ProcessLogger.cpp 
  SimpleLogger.cpp 
  StreamLogger.cpp 
  Syslog.cpp 

)
#add_library(ApacheModule  SHARED
#Module.cpp

#)
#add_library(PreloadACE  SHARED
#PreloadACE.cpp
#)

#link_directories()



target_link_libraries(Logger Generics pthread)


