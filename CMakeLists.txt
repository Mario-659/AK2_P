cmake_minimum_required(VERSION 3.16)
project(AK2_P)

set(CMAKE_CXX_STANDARD 11)

set(GOOGLETEST_VERSION 1.10.0)

enable_testing()

add_subdirectory(src)

add_subdirectory(tests)
