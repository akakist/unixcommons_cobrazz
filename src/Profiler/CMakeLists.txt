

add_library(Profiler  SHARED
    Lib/Profiler.cpp
    Parser/Parser.cpp
)
target_link_libraries(Profiler pthread)


