cmake_minimum_required(VERSION 2.8)
project(glad)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)
add_library(glad src/glad.c)
target_link_libraries(glad dl)
