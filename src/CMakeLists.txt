
add_executable(rpaudio  main.cpp)
target_link_libraries(rpaudio raspi)
target_link_libraries(rpaudio dsp)
include_directories(../include ../dsp_hfiles)



