cmake_minimum_required(VERSION 3.15)
project(reverse_string)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include/lest)

add_executable(reverse_string main.cpp)