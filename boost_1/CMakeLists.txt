cmake_minimum_required(VERSION 3.13)
project(boost_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include/lest)

add_executable(change main.cpp)
