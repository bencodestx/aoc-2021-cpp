add_executable(day1_part1 day1_part1.cpp)
target_link_libraries(day1_part1 PRIVATE aoc2021)
add_custom_command(OUTPUT day1_part1.txt COMMAND ./day1_part1 >day1_part1.txt <${CMAKE_SOURCE_DIR}/data/day1.txt)

add_custom_target(answers ALL DEPENDS day1_part1.txt)