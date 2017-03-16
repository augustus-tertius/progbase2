
cmake_minimum_required(VERSION 2.8.9)
project(lab4)

include_directories(include)

file(GLOB LIB_SOURCES "src/*.c")

add_executable(lab4 "main.c" ${LIB_SOURCES})

target_link_libraries(lab4 progbase)

project(lab4test)

add_executable(lab4test "tests/main.c" ${LIB_SOURCES})
target_link_libraries(lab4test progbase check)

