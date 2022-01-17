#pragma once

#include <range/v3/numeric/accumulate.hpp>

namespace aoc2021::day2 {
template <typename T> auto follow_planned_course(const auto &instructions) {
  const auto l = ranges::accumulate(instructions, T{});
  return l.horizontal_position * l.depth;
}
} // namespace aoc2021::day2