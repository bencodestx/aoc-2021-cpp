add_executable(day1_tests day1_tests.cpp)
target_link_libraries(day1_tests aoc2021 gtest gtest_main)

gtest_discover_tests(day1_tests)