cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Algorithms-and-Data-Structures)

include(cmake/function.cmake)

add_subdirectory(lib_easy_example)
add_subdirectory(main)
add_library(QueueLib lib_queue/queue.h lib_queue/queue.cpp)

option(BTEST "build test?" ON)

if(BTEST)
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    add_subdirectory("third_party/gtest" EXCLUDE_FROM_ALL)
    enable_testing()
    add_subdirectory(tests)
endif()

# Отдельные тестовые цели для стека и очереди - ВНЕ основного if(BTEST)
if(BTEST)
    # Тесты только для стека
    add_executable(StackTests tests/test_stack.cpp)
    target_link_libraries(StackTests EasyExample gtest gtest_main)
    
    # Тесты только для очереди  
    add_executable(QueueTests tests/test_queue.cpp)
    target_link_libraries(QueueTests QueueLib gtest gtest_main)
    
    # Добавляем новые цели в тестирование
    add_test(NAME StackTests COMMAND StackTests)
    add_test(NAME QueueTests COMMAND QueueTests)
endif()