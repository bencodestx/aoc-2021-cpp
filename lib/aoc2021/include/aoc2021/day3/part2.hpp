#pragma once

#include "aoc2021/day3/operators.hpp"
#include "aoc2021/read_vector.hpp"

#include <array>
#include <bitset>
#include <cstddef>
#include <functional>
#include <istream>

namespace aoc2021::day3 {

template <std::size_t bit_count>
auto count_bits_in_position(const std::size_t bit, const auto &reports) {
  std::size_t count{};
  for (const auto &report : reports) {
    if (report[bit]) {
      ++count;
    }
  }
  return count;
}

template <std::size_t bit_count, typename Comparison> auto rating(auto values) {
  Comparison comparison{};
  for (std::size_t bit = 0; bit < bit_count; ++bit) {
    if (std::size(values) == 1) {
      break;
    }
    const auto count =
        count_bits_in_position<bit_count>(bit_count - bit - 1, values);
    bool value_to_erase;
    if (comparison(count, std::size(values) - count)) {
      value_to_erase = false;
    } else {
      value_to_erase = true;
    }
    std::erase_if(values, [&](const auto &x) {
      return x[bit_count - bit - 1] == value_to_erase;
    });
  }
  return values[0].to_ulong();
}

template <std::size_t bit_count> auto part2(auto &in) {
  const auto reports = read_vector<std::bitset<bit_count>>(in);
  const auto oxygen_generator_rating =
      rating<bit_count, std::greater_equal<std::size_t>>(reports);
  const auto co2_scrubber_rating =
      rating<bit_count, std::less<std::size_t>>(reports);
  return oxygen_generator_rating * co2_scrubber_rating;
}
} // namespace aoc2021::day3