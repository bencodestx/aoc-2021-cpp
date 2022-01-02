add_executable(day1_tests day1.cpp)
target_link_libraries(day1_tests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(day1_tests)