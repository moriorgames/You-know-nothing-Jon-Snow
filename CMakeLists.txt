cmake_minimum_required(VERSION 3.9)
project(MoriorGamesDNA)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

add_subdirectory(src)

add_executable(main main.cpp)

target_link_libraries(main moriorgames_dna)
