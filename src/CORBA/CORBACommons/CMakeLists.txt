#cmake_minimum_required (VERSION 2.6)




add_library(CORBACommons  SHARED
  AceLogger.cpp 
  CorbaAdapters.cpp 
  CorbaClientAdapter.cpp 
  CorbaServerAdapter.cpp 
  ProcessControlImpl.cpp 
  Reactor.cpp 
)
