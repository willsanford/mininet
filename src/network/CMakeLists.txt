cmake_minimum_required(VERSION 3.14)

project(NetworkLib)

add_library(NetworkLib SHARED net.cpp)
target_link_libraries(NetworkLib MathLib LogsLib)
target_include_directories(NetworkLib PUBLIC ../logs ../math)