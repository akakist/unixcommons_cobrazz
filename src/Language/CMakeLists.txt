#cmake_minimum_required (VERSION 2.6)


#include_directories(   /usr/include/apr-1       )


add_library(Language  SHARED
KoreanSegmentor/Klt.cpp
KoreanSegmentor/Korean.cpp
KoreanSegmentor/Moran.cpp
JapaneseSegmentor/Mecab.cpp
#ChineeseSegmentor/NLPIR.cpp
BLogic/NormalizeTrigger.cpp
SegmentorUtil/Application.cpp
GenericSegmentor/Polyglot.cpp
Polyglot/DictionaryLoader.cpp

)
#add_library(ApacheModule  SHARED
#Module.cpp

#)
#add_library(PreloadACE  SHARED
#PreloadACE.cpp
#)

#link_directories()



target_link_libraries(Language Generics)


