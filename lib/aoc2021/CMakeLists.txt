add_library(aoc2021 INTERFACE)
target_include_directories(aoc2021 INTERFACE include)
target_link_libraries(aoc2021 INTERFACE range-v3)

add_subdirectory(include/aoc2021/day1/test)
add_subdirectory(include/aoc2021/day2/test)