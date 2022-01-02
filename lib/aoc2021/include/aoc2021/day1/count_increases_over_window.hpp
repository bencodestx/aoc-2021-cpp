#pragma once

namespace aoc2021::day1 {
template <size_t window_size>
constexpr auto count_increases_over_window(const auto &values) {
  size_t count{};
  for (auto it = std::cbegin(values); it != (std::cend(values) - window_size);
       ++it) {
    if (*(it + window_size) > *it) {
      ++count;
    }
  }
  return count;
};
} // namespace aoc2021::day1
