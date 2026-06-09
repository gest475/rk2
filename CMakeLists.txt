cmake_minimum_required(VERSION 3.10)
project(chain_of_responsibility)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(chain_app src/main.cpp)
add_executable(chain_tests tests/test_chain.cpp)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz)
FetchContent_MakeAvailable(googletest)

target_link_libraries(chain_tests gtest_main)

enable_testing()
add_test(NAME tests COMMAND chain_tests)

include(CPack)
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_VERSION "1.0.0")
set(CPACK_PACKAGE_CONTACT "student@example.com")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "BMSTU Student <student@example.com>")
set(CPACK_PACKAGE_FILE_NAME "chain-of-responsibility_${CPACK_PACKAGE_VERSION}_amd64")
set(CPACK_DEBIAN_PACKAGE_DEPENDS "")
install(TARGETS chain_app DESTINATION bin)
install(FILES include/chain.hpp DESTINATION include/chain_of_responsibility)
