#cmake_minimum_required (VERSION 2.6)


#include_directories(   /usr/include/apr-1       )


add_library(String  SHARED
  
  
    Analyzer.cpp 
  AsciiStringManip.cpp 
  BasicAnalyzer.cpp 
  InterConvertion.cpp 
  RegEx.cpp 
  StringManip.cpp 
  TextTemplate.cpp 
  UnicodeNormalizer.cpp 
  UnicodeNormTables.cpp 
  UnicodeSymbol.cpp 
  UTF8AllProperties.cpp 
  UTF8Case.cpp 
  UTF8CaseLower.cpp 
  UTF8CaseSimplify.cpp 
  UTF8CaseUniform.cpp 
  UTF8CaseUpper.cpp 
  UTF8Category.cpp 
  UTF8IsDigit.cpp 
  UTF8IsLetter.cpp 
  UTF8IsLowerLetter.cpp 
  UTF8IsUpperLetter.cpp 
  UTF8IsSpace.cpp 
  UTF8IsTitleLetter.cpp 

)
#add_library(ApacheModule  SHARED
#Module.cpp

#)
#add_library(PreloadACE  SHARED
#PreloadACE.cpp
#)

target_link_libraries(String Generics pcre)


