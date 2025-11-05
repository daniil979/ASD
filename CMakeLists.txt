cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Algorithms-and-Data-Structures)

include(cmake/function.cmake)

add_subdirectory(lib_easy_example)
add_subdirectory(main)
add_library(QueueLib lib_queue/queue.h lib_queue/queue.cpp)
add_library(AlgorithmsLib lib_algorithms/algorithms.cpp lib_algorithms/algorithms.h)
target_link_libraries(AlgorithmsLib EasyExample)

# Добавляем DSU библиотеку
add_library(DSULib lib_dsu/dsu.cpp lib_dsu/dsu.h)

option(BTEST "build test?" ON)

if(BTEST)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory("third_party/gtest" EXCLUDE_FROM_ALL)
    enable_testing()
    add_subdirectory(tests)
    
    # Отдельные тестовые цели
    add_executable(StackTests tests/test_stack.cpp)
    target_link_libraries(StackTests EasyExample gtest gtest_main)
    
    add_executable(QueueTests tests/test_queue.cpp)
    target_link_libraries(QueueTests QueueLib gtest gtest_main)
    
    add_executable(AlgorithmsTests tests/test_algorithms.cpp)
    target_link_libraries(AlgorithmsTests AlgorithmsLib gtest gtest_main)
    
    # Добавляем тесты для DSU
    add_executable(DSUTests tests/test_dsu.cpp)
    target_link_libraries(DSUTests DSULib gtest gtest_main)
    
    add_test(NAME StackTests COMMAND StackTests)
    add_test(NAME QueueTests COMMAND QueueTests)
    add_test(NAME AlgorithmsTests COMMAND AlgorithmsTests)
    add_test(NAME DSUTests COMMAND DSUTests)
endif()
