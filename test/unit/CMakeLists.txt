cmake_minimum_required(VERSION 3.14)
project(my_project)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Get all test files in the 'unit' directory
file(GLOB TEST_SOURCES "srcs/*.cpp")

# Add the source file where get_current_time(timeval*) is defined
list(APPEND TEST_SOURCES "../../srcs/utils.c") # C言語のソースファイルを追加
list(APPEND TEST_SOURCES "../../srcs/philosopher.c") # C言語のソースファイルを追加
list(APPEND TEST_SOURCES "../../srcs/ft_atoi.c") # C言語のソースファイルを追加

# Add test executable target
add_executable(runUnitTests ${TEST_SOURCES})

# Specify include directories for target
target_include_directories(runUnitTests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../../includes)

# Link with GoogleTest
target_link_libraries(runUnitTests gtest gtest_main)

# Add test
enable_testing()
add_test(NAME unit_tests COMMAND runUnitTests)