cmake_minimum_required(VERSION 3.5.1)

project(AdaptiveLearningLibrary)

set(CMAKE_CXX_STANDARD 17)

include_directories(eigen-git-mirror/Eigen)

add_subdirectory(googletest)

add_subdirectory(core)

add_subdirectory(test)

