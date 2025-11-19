cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Algorithms-and-Data-Structures)

# Только две библиотеки
add_library(LinkedListLib lib_linked_list/linked_list.h)
add_library(AlgorithmsLib 
    lib_algorithms/algorithms.cpp 
    lib_algorithms/algorithms.h
)

option(BTEST "build test?" ON)

if(BTEST)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory("third_party/gtest" EXCLUDE_FROM_ALL)
    enable_testing()
    
    add_executable(LinkedListTests tests/test_linked_list.cpp)
    target_link_libraries(LinkedListTests LinkedListLib gtest gtest_main)
    
    add_executable(AlgorithmsTests tests/test_algorithms.cpp)
    target_link_libraries(AlgorithmsTests AlgorithmsLib gtest gtest_main)
    
    add_test(NAME LinkedListTests COMMAND LinkedListTests)
    add_test(NAME AlgorithmsTests COMMAND AlgorithmsTests)
endif()

add_executable(Application main/main.cpp)
