cmake_minimum_required(VERSION 3.14)
project(mininet)


set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)

# Include the Google Test Sources
set(TEST_SOURCES test/main.cpp
		 test/log_test.cpp
		 test/utils_test.cpp
		 test/math_test.cpp
		 test/tensor_test.cpp)

add_executable(mininet ${TEST_SOURCES})

# Add library subdirectories and include thos directories
add_subdirectory(src/math)
add_subdirectory(src/logs)
add_subdirectory(src/network)

target_include_directories(mininet PUBLIC
			   src/logs
			   src/math
			   src/network)

target_link_libraries(mininet PUBLIC
		      gtest
			  pthread
		      LogsLib
		      MathLib
			  NetworkLib)

target_compile_features(mininet PRIVATE cxx_std_17)
