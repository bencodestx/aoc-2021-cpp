add_executable(day4_tests day4_tests.cpp)
target_link_libraries(day4_tests aoc2021 gtest gtest_main)

gtest_discover_tests(day4_tests)