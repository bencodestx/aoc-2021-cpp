#pragma once

#include <bitset>
#include <cstddef>
#include <istream>

namespace aoc2021::day3 {
template <std::size_t bit_count>
std::istream &operator>>(std::istream &in, std::bitset<bit_count> &d) {
  return (in >> d.bits);
}
} // namespace aoc2021::day3