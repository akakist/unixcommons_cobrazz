#cmake_minimum_required (VERSION 2.6)


#include_directories(   /usr/include/apr-1       )


add_library(XMLUtility  SHARED
  DOMDocumentAdapter.cpp 
  ParseErrorReporter.cpp 
  StringManip.cpp 
  Utility.cpp 

)
#add_library(ApacheModule  SHARED
#Module.cpp

#)
#add_library(PreloadACE  SHARED
#PreloadACE.cpp
#)

#link_directories()



target_link_libraries(XMLUtility xerces-c)


