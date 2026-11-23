cmake_minimum_required(VERSION 3.16)
project(OOPMidterm LANGUAGES CXX)

include(files.cmake)

add_library(OOPMidterm STATIC ${OOPMIDTERM_SOURCES})
target_include_directories(OOPMidterm PUBLIC include)
target_compile_features(OOPMidterm PUBLIC cxx_std_17)
