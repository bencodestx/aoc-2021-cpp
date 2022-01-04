#pragma once

#include <istream>
#include <string>

namespace aoc2021::day2 {
struct instruction {
  std::string direction{};
  int distance{};
};

std::istream &operator>>(std::istream &is, instruction &x) {
  return is >> x.direction >> x.distance;
}
} // namespace aoc2021::day2
