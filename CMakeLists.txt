cmake_minimum_required(VERSION 3.16)
project(aoc-2021-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include(GoogleTest)

add_subdirectory(lib)
add_subdirectory(src)

add_subdirectory(vendor/googletest)
add_subdirectory(vendor/range-v3)