cmake_minimum_required(VERSION 3.14)
project(cpp_nn)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)


# Include the Log Library
add_subdirectory(src/logs)


# Include the Google Test Sources
set(TEST_SOURCES test/main.cpp
		 test/log_test.cpp)

add_executable(cpp_nn ${TEST_SOURCES})
target_include_directories(cpp_nn PUBLIC src/logs)
target_link_directories(cpp_nn PUBLIC src/logs)

target_link_libraries(cpp_nn PUBLIC
		      gtest
		      LogsLib)
