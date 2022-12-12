
set(proj "TestSelect")

add_executable(${proj}

Application.cpp  

)


target_link_libraries(${proj} Generics Logger TestCommons2)


