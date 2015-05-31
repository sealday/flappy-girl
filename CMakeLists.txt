cmake_minimum_required(VERSION 3.2)
project(flappy_girl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(flappy_girl ${SOURCE_FILES})

# glad
add_subdirectory(glad)
include_directories(glad/include)
target_link_libraries(flappy_girl glad)

# glfw
add_subdirectory(glfw)
include_directories(glfw/include)
target_link_libraries(flappy_girl glfw ${GLFW_LIBRARIES})

# glm
include_directories(glm)
