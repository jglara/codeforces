cmake_minimum_required(VERSION 2.8)

project (convert_to_ones)

# Set the project source dir (just convention)
set( CMAKE_SOURCES
  convert_to_ones.cc
)

add_executable(${PROJECT_NAME} ${CMAKE_SOURCES})
add_definitions( -g --std=c++11 -Wall -Wextra -Wpedantic)
