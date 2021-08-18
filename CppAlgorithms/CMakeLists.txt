cmake_minimum_required(VERSION 3.17)
project(CppAlgorithms)

set(CMAKE_CXX_STANDARD 11)

add_executable(binarysearch binarysearch/BinarySearch.cpp)
add_executable(array array/GassStation.cpp)
add_executable(hashmap hashmap/GoodPairs.cpp)
add_subdirectory(dfs)
add_subdirectory(dp)
add_subdirectory(list)
add_subdirectory(backtracking)
add_subdirectory(recursive)
