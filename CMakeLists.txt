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

# ИСПРАВЛЕННЫЙ БЛОК: Загрузка с жестким указанием имени файла и хэша для обхода багов парсинга в CMake 3.31+
include(FetchContent)
FetchContent_Declare(
    googletest
    URL "https://github.com"
    DOWNLOAD_NAME googletest-v1.14.0.zip
    URL_HASH SHA256=927827c1eeac000bf22edcdcf4ca594665401568e306a9d736629cb6076aed9a
    DOWNLOAD_NO_PROGRESS ON
)
FetchContent_MakeAvailable(googletest)
target_link_libraries(chain_tests gtest_main)

enable_testing()
add_test(NAME tests COMMAND chain_tests)

install(TARGETS chain_app DESTINATION bin)

set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME "chain-app")
set(CPACK_PACKAGE_VERSION "${PROJECT_VERSION}")
set(CPACK_PACKAGE_MAINTAINER "Student <student@university.com>")
set(CPACK_PACKAGE_DESCRIPTION "Chain of Responsibility Lab Assignment")

include(CPack)
