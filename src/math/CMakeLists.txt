cmake_minimum_required(VERSION 3.14)

project(MathLib)

add_library(MathLib SHARED core.cpp tensor.cpp tensor_math.cpp activations.cpp)
target_link_libraries(MathLib LogsLib)
target_include_directories(MathLib PUBLIC ../logs)