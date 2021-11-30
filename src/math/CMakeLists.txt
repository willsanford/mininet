cmake_minimum_required(VERSION 3.14)

project(MathLib)

add_library(MathLib SHARED core.cpp tensor.cpp tensor_math.cpp)
target_link_libraries(MathLib LogsLib)
target_include_directories(MathLib PUBLIC ../logs)