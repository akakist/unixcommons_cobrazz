#cmake_minimum_required (VERSION 2.6)


#include_directories(   /usr/include/apr-1       )


add_library(Generics  SHARED
  Allocator.cpp 
  ActiveObject.cpp 
  AppUtils.cpp 
  CommonDecimal.cpp 
  CompositeActiveObject.cpp 
  CountryCodeManip.cpp 
  CRC.cpp 
  Crypto.cpp 
  Hash.cpp 
  Listener.cpp 
  MMap.cpp 
  MemBuf.cpp 
  Network.cpp 
  Periodic.cpp 
  Plug.cpp 
  Proc.cpp 
  Rand.cpp 
  Scheduler.cpp 
  Singleton.cpp 
  Statistics.cpp 
  TaskRunner.cpp 
  TaskPool.cpp 
  Time.cpp 
  ThreadRunner.cpp 
  Uuid.cpp 
  Values.cpp 
 ../String/Analyzer.cpp
../String/AsciiStringManip.cpp
../String/BasicAnalyzer.cpp
../String/InterConvertion.cpp
../String/RegEx.cpp
../String/StringManip.cpp
../String/TextTemplate.cpp
../String/UTF8AllProperties.cpp
../String/UTF8Case.cpp
../String/UTF8CaseLower.cpp
../String/UTF8CaseSimplify.cpp
../String/UTF8CaseUniform.cpp
../String/UTF8CaseUpper.cpp
../String/UTF8Category.cpp
../String/UTF8IsDigit.cpp
../String/UTF8IsLetter.cpp
../String/UTF8IsLowerLetter.cpp
../String/UTF8IsSpace.cpp
../String/UTF8IsTitleLetter.cpp
../String/UTF8IsUpperLetter.cpp
../String/UnicodeNormTables.cpp
../String/UnicodeNormalizer.cpp
../String/UnicodeSymbol.cpp


)
#add_library(ApacheModule  SHARED
#Module.cpp

#)
#add_library(PreloadACE  SHARED
#PreloadACE.cpp
#)

#link_directories()



target_link_libraries(Generics Sync  pthread crypto ev pcre dl)


