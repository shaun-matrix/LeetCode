cmake_minimum_required(VERSION 3.22)
project(LeetCode)

set(CMAKE_CXX_STANDARD 14)

#project include dir
include_directories(${PROJECT_SOURCE_DIR}/common)

add_executable(two_sum vector/two_sum.cpp)
add_executable(remove_duplicates vector/remove_duplicates.cpp)
add_executable(max_sub_array vector/max_sub_array.cpp)
add_executable(roman_to_int string/roman_to_int.cpp)
add_executable(length_of_longest_substring string/length_of_longest_substring.cpp)
add_executable(get_intersection_node linked_list/get_intersection_node.cpp)
