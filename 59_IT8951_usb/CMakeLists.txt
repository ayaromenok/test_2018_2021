cmake_minimum_required(VERSION 3.5)

project(59_IT8951_usb LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(59_IT8951_usb main.cpp)

target_link_libraries(59_IT8951_usb usb-1.0)
