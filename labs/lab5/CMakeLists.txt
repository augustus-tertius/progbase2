cmake_minimum_required(VERSION 2.8.9)
project(lab5) 

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99") 
# 
# Common settings 
# 

# adds ./include to compiler include directories 
#include_directories(include) 
include_directories(/usr/include/libxml2)

# compiles code files from ./src folder 
file(GLOB LIB_SOURCES "src/*.c") 

# 
# first project (static lib) 
# 
project (mylab5) 

# to build static library target with name libmtmodule.a 
add_library(${CMAKE_PROJECT_NAME} STATIC ${LIB_SOURCES}) 

target_link_libraries(${CMAKE_PROJECT_NAME} progbase)
target_link_libraries(${CMAKE_PROJECT_NAME} libxml2.so)
target_link_libraries(${CMAKE_PROJECT_NAME} libjansson.so)

# to install library headers 
install( 
DIRECTORY include/ DESTINATION /usr/local/include 
FILES_MATCHING PATTERN "*.h" 
) 

# Set the location for library installation 
# Use "sudo make install" in build directory to apply 
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION /usr/local/lib) 


# 
# Test project 
# 

project(lab) 

add_executable(${CMAKE_PROJECT_NAME} "main.c" ${LIB_SOURCES}) 
set_property(TARGET ${CMAKE_PROJECT_NAME} PROPERTY C_STANDARD 99) 
target_link_libraries(${CMAKE_PROJECT_NAME} check jansson xml2 progbase mylab5)