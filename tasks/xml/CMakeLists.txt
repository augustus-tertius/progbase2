
cmake_minimum_required(VERSION 2.8.9)
project(myxml)

include_directories(include)
include_directories(/usr/include/libxml2)

file(GLOB SOURCES "main.c" "src/*.c")

add_executable(myxml ${SOURCES})

target_link_libraries(myxml libxml2.so)
