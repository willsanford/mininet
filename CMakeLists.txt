cmake_minimum_required(VERSION 3.14)
project(cpp_nn)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)

# Include the Google Test Sources
set(TEST_SOURCES test/main.cpp
		 test/log_test.cpp
		 test/tensor_test.cpp)

add_executable(cpp_nn ${TEST_SOURCES})

# Add library subdirectories and include thos directories
add_subdirectory(src/math)
add_subdirectory(src/logs)
target_include_directories(cpp_nn PUBLIC 
			   src/logs
			   src/math)

target_link_libraries(cpp_nn PUBLIC
		      gtest
		      LogsLib
		      MathLib)
