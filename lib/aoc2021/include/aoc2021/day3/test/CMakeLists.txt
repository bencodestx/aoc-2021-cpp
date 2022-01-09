add_executable(day3_tests day3_tests.cpp)
target_link_libraries(day3_tests aoc2021 gtest gtest_main)

gtest_discover_tests(day3_tests)