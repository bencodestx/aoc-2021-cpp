#pragma once

#include <range/v3/algorithm/count_if.hpp>
#include <range/v3/numeric/accumulate.hpp>
#include <range/v3/view/sliding.hpp>
#include <range/v3/view/transform.hpp>

namespace aoc2021::day1 {

template <std::size_t window_size>
constexpr auto count_increases_over_window(const auto &depth_measurements) {
  constexpr auto sum_of_window = [](const auto &x) {
    return ranges::accumulate(x, 0);
  };

  constexpr auto is_depth_increase = [](const auto &x) { return x[1] > x[0]; };

  return ranges::count_if(
      depth_measurements | ranges::views::sliding(window_size) |
          ranges::views::transform(sum_of_window) | ranges::views::sliding(2),
      is_depth_increase);
};

} // namespace aoc2021::day1
