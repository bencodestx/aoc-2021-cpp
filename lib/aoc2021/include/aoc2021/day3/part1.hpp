#pragma once

#include "aoc2021/read_vector.hpp"

#include <array>
#include <bitset>
#include <cstddef>
#include <istream>

namespace aoc2021::day3 {
template <std::size_t bit_count>
std::istream &operator>>(std::istream &in, std::bitset<bit_count> &d) {
  return (in >> d.bits);
}

template <std::size_t bit_count> auto count_set_bits(const auto &reports) {
  std::array<std::size_t, bit_count> counts{};
  for (const auto &report : reports) {
    for (std::size_t bit = 0; bit < bit_count; ++bit) {
      if (report[bit]) {
        ++counts[bit];
      }
    }
  }
  return counts;
}

template <std::size_t bit_count> auto part1(auto &in) {
  const auto reports = read_vector<std::bitset<bit_count>>(in);
  const auto counts = count_set_bits<bit_count>(reports);
  std::bitset<bit_count> bits{};
  for (std::size_t bit = 0; bit < bit_count; ++bit) {
    if (counts[bit] > (std::size(reports) / 2)) {
      bits[bit] = 1;
    }
  }
  const auto gamma_rate = bits.to_ulong();
  bits.flip();
  const auto epsilon_rate = bits.to_ulong();
  return gamma_rate * epsilon_rate;
}
} // namespace aoc2021::day3