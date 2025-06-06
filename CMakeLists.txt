cmake_minimum_required(VERSION 3.10) project(CommandPattern CXX)

set(CMAKE_CXX_STANDARD 11) set(CMAKE_CXX_STANDARD_REQUIRED ON)

Static library for Command pattern classes

add_library(command_pattern STATIC ConcreteCommandA.cpp ConcreteCommandB.cpp ConcreteReceiverX.cpp ConcreteReceiverY.cpp Invoker.cpp )

Specify include directories for the library

target_include_directories(command_pattern PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

Executable

add_executable(command_demo main.cpp) target_link_libraries(command_demo PRIVATE command_pattern)

Enable testing

enable_testing()

Find Google Test

find_package(GTest REQUIRED) include_directories(${GTEST_INCLUDE_DIRS})

Test executable

add_executable(command_tests test_ConcreteCommandA.cpp test_ConcreteCommandB.cpp test_ConcreteReceiverX.cpp test_ConcreteReceiverY.cpp test_Invoker.cpp ) target_link_libraries(command_tests PRIVATE command_pattern ${GTEST_LIBRARIES} ${GTEST_MAIN_LIBRARIES}) add_test(NAME CommandTests COMMAND command_tests)
