cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(simpleNN)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(simpleNN simpleNN.cpp)
target_link_libraries(simpleNN "${TORCH_LIBRARIES}")
set_property(TARGET simpleNN PROPERTY CXX_STANDARD 14)
