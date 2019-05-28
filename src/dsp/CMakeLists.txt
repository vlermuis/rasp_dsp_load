include_directories(../../include ../../dsp_hfiles)
add_library(dsp  STATIC Dsp.cpp Dsp1451.cpp Dsp1761.cpp)
target_link_libraries(dsp raspi)


