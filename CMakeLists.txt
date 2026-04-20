cmake_minimum_required(VERSION 3.14)
project(cckit CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Configure directories
add_subdirectory(libs)

# Configure Testing
enable_testing()
add_subdirectory(tests)
