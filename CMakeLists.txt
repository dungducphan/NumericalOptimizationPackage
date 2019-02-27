cmake_minimum_required(VERSION 3.13)
project(NumericalOptimization)

set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(NumericalOptimization main.cpp NumericalOptimizer.cpp NumericalOptimizer.h)