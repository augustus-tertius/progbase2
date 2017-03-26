cmake_minimum_required(VERSION 3.5.1)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

include_directories(cmake-build-debug)
include_directories(include)

set(SOURCE_FILES main.cpp src/Ball.cpp)
add_executable(cpp ${SOURCE_FILES})