cmake_minimum_required(VERSION 3.10)
project(chain_of_responsibility)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(chain_app src/main.cpp)
target_link_libraries(chain_app stdc++)

add_executable(chain_tests tests/test_chain.cpp)
target_link_libraries(chain_tests stdc++)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz)
FetchContent_MakeAvailable(googletest)

target_link_libraries(chain_tests gtest_main)

enable_testing()
add_test(NAME tests COMMAND chain_tests)
