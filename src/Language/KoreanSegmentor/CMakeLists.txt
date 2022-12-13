
add_library(KoreanSegmentor  SHARED
  Korean.cpp 
  Klt.cpp 
  Moran.cpp 
  

)

target_link_libraries(KoreanSegmentor Generics)


