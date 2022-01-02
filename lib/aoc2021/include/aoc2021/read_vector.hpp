#pragma once

#include <vector>

namespace aoc2021 {
template <typename T> auto read_vector(auto &in) {
  T value;
  std::vector<T> values{};
  while (in >> value) {
    values.emplace_back(value);
  }
  return values;
}
} // namespace aoc2021