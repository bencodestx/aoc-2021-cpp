#pragma once

#include "aoc2021/read_vector.hpp"
#include "follow_planned_course.hpp"
#include "instruction.hpp"
#include "part2_location.hpp"

namespace aoc2021::day2 {

auto part2(auto &in) {
  const auto instructions = read_vector<instruction>(in);
  return follow_planned_course<part2_location>(instructions);
}

} // namespace aoc2021::day2