cmake_minimum_required(VERSION 2.8.9)

SET(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(include)
file(GLOB LIB_SOURCES "src/*.cpp")

project(threads)

# to build executable target with name a.out
add_executable(${CMAKE_PROJECT_NAME} "main.cpp" ${LIB_SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} m pthread progbase-cpp progbase)