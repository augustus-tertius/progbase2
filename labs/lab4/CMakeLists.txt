
cmake_minimum_required(VERSION 2.8.9)
project(lab4)

include_directories(include)

file(GLOB SOURCES "main.c" "src/*.c")

add_executable(lab4 ${SOURCES})

target_link_libraries(lab4 progbase)
