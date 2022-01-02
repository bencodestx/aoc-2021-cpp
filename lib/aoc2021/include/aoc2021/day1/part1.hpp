#pragma once

#include "aoc2021/day1/count_increases_over_window.hpp"
#include "aoc2021/read_vector.hpp"

namespace aoc2021::day1 {
auto part1(auto &in) {
  auto values = read_vector<int>(in);
  return count_increases_over_window<1>(values);
}
} // namespace aoc2021::day1