set(proj "CaseUtil")

add_library(CaseUtil  SHARED
CaseUtil.cpp
)


target_link_libraries(CaseUtil Generics)


