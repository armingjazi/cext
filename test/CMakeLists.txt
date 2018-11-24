include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(runALLTests LibraryTestCase.cpp EventTestCase.cpp)

target_link_libraries(runALLTests gtest gmock gtest_main)
target_link_libraries(runALLTests ALLCore)
#target_link_libraries(runAllTests Eigen3::Eigen)


if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)