add_executable(day2_tests day2_tests.cpp)
target_link_libraries(day2_tests aoc2021 gtest gtest_main)

gtest_discover_tests(day2_tests)