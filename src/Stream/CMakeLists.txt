#cmake_minimum_required (VERSION 2.6)


#include_directories(   /usr/include/apr-1       )


add_library(Stream  SHARED
  BinaryStream.cpp 
  BzlibStreams.cpp 
  FileStreamBuf.cpp 
  GzipStreams.cpp 
  SocketStream.cpp 

)
#add_library(ApacheModule  SHARED
#Module.cpp

#)
#add_library(PreloadACE  SHARED
#PreloadACE.cpp
#)

target_link_libraries(Stream z bz2 ACE)


