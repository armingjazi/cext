add_executable(run_all_tests LibraryTestCase.cpp EventTestCase.cpp AlignedArrayTestCase.cpp AlignedCArrayTestCase.cpp)

target_link_libraries(run_all_tests gtest gmock gtest_main)
target_link_libraries(run_all_tests all_core)
#target_link_libraries(runAllTests Eigen3::Eigen)

if (APPLE)
    add_definitions(-DGTEST_USE_OWN_TR1_TUPLE)
    add_definitions(-D__GLIBCXX__)
endif (APPLE)