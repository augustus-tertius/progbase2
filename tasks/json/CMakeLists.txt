
cmake_minimum_required(VERSION 2.8.9)
project(myjson)

include_directories(include)

file(GLOB SOURCES "main.c" "src/*.c")

add_executable(myjson ${SOURCES})
target_link_libraries(myjson sfml-app -lsfml-graphics -lsfml-window -lsfml-system)

