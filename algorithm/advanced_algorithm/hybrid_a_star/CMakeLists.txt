cmake_minimum_required(VERSION 3.5)
project(hybrid_A_start)
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp hybrid_breadth_first.cpp)

add_executable(a_search ${SOURCE_FILES})