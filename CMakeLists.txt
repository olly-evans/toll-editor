cmake_minimum_required(VERSION 3.16)
project(toll LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add include directory for headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Collect all source files from src/
file(GLOB SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Create the executable from source files
add_executable(toll ${SOURCES})