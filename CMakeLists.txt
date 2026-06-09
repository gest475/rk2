cmake_minimum_required(VERSION 3.10)
project(chain_of_responsibility VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(chain_app src/main.cpp)
add_executable(chain_tests tests/test_chain.cpp)

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    target_link_libraries(chain_app stdc++)
    target_link_libraries(chain_tests stdc++)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    target_link_libraries(chain_app c++)
    target_link_libraries(chain_tests c++)
endif()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# ИСПРАВЛЕНИЕ: Добавили библиотеку 'm' (libm) для устранения ошибки nextafter
target_link_libraries(chain_tests ${GTEST_LIBRARIES} pthread m)

enable_testing()
add_test(NAME tests COMMAND chain_tests)

install(TARGETS chain_app DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "chain-app")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_MAINTAINER "Arina Artemenko <arina@university.com>")
set(CPACK_PACKAGE_DESCRIPTION "Chain of Responsibility Lab Assignment RK2")

include(CPack)
