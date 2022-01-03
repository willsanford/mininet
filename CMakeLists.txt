cmake_minimum_required(VERSION 3.14)
project(mininet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED)

add_library(mininet SHARED src/network/net.cpp)

# Add library subdirectories and include thos directories
add_subdirectory(src/math)
add_subdirectory(src/logs)
# add_subdirectory(src/network)

target_include_directories(mininet PUBLIC
			   src/logs
			   src/math)

target_link_libraries(mininet PUBLIC
		    gtest
			  pthread
		    LogsLib
		    MathLib)

target_compile_features(mininet PRIVATE cxx_std_17)

# Produce the unit tests
# Include the Google Test Sources
set(TEST_SOURCES test/unit_test/main.cpp
		 test/unit_test/log_test.cpp
		 test/unit_test/utils_test.cpp
		 test/unit_test/math_test.cpp
		 test/unit_test/tensor_test.cpp)

add_executable(unittest ${TEST_SOURCES})

target_link_libraries(unittest mininet) 

# Produce the speed test

# Include the test sources
set(SPEED_TEST_SOURCES test/speed_test/speed_test.cpp)

add_executable(speedtest ${SPEED_TEST_SOURCES})

target_link_libraries(speedtest mininet) 