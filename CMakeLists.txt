cmake_minimum_required(VERSION 3.10)
project(psuedo)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(psuedo ${SOURCES})
