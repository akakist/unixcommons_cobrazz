
add_library(LinguistUtil  SHARED
Application.cpp
)

target_link_libraries(LinguistUtil Generics BLogic GenericSegmentor Polyglot)


