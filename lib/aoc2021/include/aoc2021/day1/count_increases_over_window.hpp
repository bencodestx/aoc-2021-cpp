#pragma once

#include <cstddef>
#include <range/v3/algorithm/count_if.hpp>
#include <range/v3/view/drop.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/zip.hpp>

namespace aoc2021::day1 {

template <std::size_t window_size>
constexpr auto count_increases_over_window(const auto &values) {
  using ranges::views::zip, ranges::views::drop, ranges::count_if;
  using std::get;

  const auto values_before_and_after_window =
      zip(values, values | drop(window_size));

  constexpr auto after_is_larger = [](const auto &x) {
    return get<1>(x) > get<0>(x);
  };

  return count_if(values_before_and_after_window, after_is_larger);
};

} // namespace aoc2021::day1
