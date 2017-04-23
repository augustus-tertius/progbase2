cmake_minimum_required(VERSION 2.8.9)

#
# Common settings
#

#
# first project 
#
project (server)
include_directories(include)
file(GLOB SOURCES "src/*.c")

add_executable(${CMAKE_PROJECT_NAME} "server.c" ${SOURCES})
target_link_libraries(${CMAKE_PROJECT_NAME} progbase)
#
# Second project
#

project (client)
add_executable(${CMAKE_PROJECT_NAME} "client.c")
target_link_libraries(${CMAKE_PROJECT_NAME} progbase)
