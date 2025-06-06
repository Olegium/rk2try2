cmake_minimum_required(VERSION 3.10)
project(CommandPattern CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(command_pattern STATIC
    src/ConcreteCommandA.cpp
    src/ConcreteCommandB.cpp
    ConcreteReceiverX.cpp
    ConcreteReceiverY.cpp
    Invoker.cpp
)

#Specify include directories for the library
target_include_directories(command_pattern PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(command_demo main.cpp)
target_link_libraries(command_demo PRIVATE command_pattern)

enable_testing()

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(subjectTest CommandPatternTests.cpp)
target_link_libraries(subjectTest gtest_main observer_lib)
add_test(NAME subjectTest COMMAND subjectTest)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_NAME "observer-pattern")
set(CPACK_PACKAGE_VERSION "1.0")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "gremlin979")
include(CPack)
