cmake_minimum_required(VERSION 3.16)
project(toll LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Only source files.
add_executable(toll main.cpp editor.hpp)