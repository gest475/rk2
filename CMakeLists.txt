cmake_minimum_required(VERSION 3.10)
project(chain_of_responsibility)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(chain_app src/main.cpp)
add_executable(chain_tests tests/test_chain.cpp)

# Явно указываем стандартную библиотеку C++ для GCC и Clang
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(chain_app stdc++)
    target_link_libraries(chain_tests stdc++)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_link_libraries(chain_app c++)
    target_link_libraries(chain_tests c++)
endif()

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz)
FetchContent_MakeAvailable(googletest)

target_link_libraries(chain_tests gtest_main)

enable_testing()
add_test(NAME tests COMMAND chain_tests)
