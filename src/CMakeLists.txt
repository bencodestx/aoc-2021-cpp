add_executable(day1_part1 day1_part1.cpp)
target_link_libraries(day1_part1 PRIVATE aoc2021)
add_custom_command(OUTPUT day1_part1.txt COMMAND ./day1_part1 >day1_part1.txt <${CMAKE_SOURCE_DIR}/data/day1.txt DEPENDS day1_part1)

add_executable(day1_part2 day1_part2.cpp)
target_link_libraries(day1_part2 PRIVATE aoc2021)
add_custom_command(OUTPUT day1_part2.txt COMMAND ./day1_part2 >day1_part2.txt <${CMAKE_SOURCE_DIR}/data/day1.txt DEPENDS day1_part2)

add_executable(day2_part1 day2_part1.cpp)
target_link_libraries(day2_part1 PRIVATE aoc2021)
add_custom_command(OUTPUT day2_part1.txt COMMAND ./day2_part1 >day2_part1.txt <${CMAKE_SOURCE_DIR}/data/day2.txt DEPENDS day2_part1)

add_executable(day2_part2 day2_part2.cpp)
target_link_libraries(day2_part2 PRIVATE aoc2021)
add_custom_command(OUTPUT day2_part2.txt COMMAND ./day2_part2 >day2_part2.txt <${CMAKE_SOURCE_DIR}/data/day2.txt DEPENDS day2_part2)

add_custom_target(answers ALL DEPENDS day1_part1.txt day1_part2.txt day2_part1.txt day2_part2.txt)