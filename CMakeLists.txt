cmake_minimum_required(VERSION 3.10)

project(all)

set(CMAKE_CXX_STANDARD 17)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Don't build benchmark tests." FORCE)

include_directories(eigen-git-mirror/Eigen)

add_subdirectory(googletest)

add_subdirectory(benchmark)

add_subdirectory(core)

add_subdirectory(test)

add_subdirectory(mircoBenchmark)

