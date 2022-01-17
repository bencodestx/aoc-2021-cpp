#pragma once

#include "aoc2021/day1/count_increases_over_window.hpp"
#include "aoc2021/read_vector.hpp"

namespace aoc2021::day1 {
auto part2(auto &in) {
  return count_increases_over_window<3>(read_vector<int>(in));
}
} // namespace aoc2021::day1