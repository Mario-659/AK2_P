cmake_minimum_required(VERSION 3.16)
project(AK2_P)

set(CMAKE_CXX_STANDARD 11)

set(GOOGLETEST_VERSION 1.10.0)

set(Boost_INCLUDE_DIR D:/Programming/MinGW/include)
set(Boost_LIBRARY_DIR D:/Programming/MinGW/lib)
find_package(Boost COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIR})

enable_testing()

add_subdirectory(src)

add_subdirectory(tests)
