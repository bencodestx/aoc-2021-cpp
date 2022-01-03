#pragma once

#include "aoc2021/read_vector.hpp"

#include <string>

namespace aoc2021::day2 {
struct instruction {
  std::string direction{};
  int distance{};
};

struct location {
  int horizontal_position{};
  int depth{};

  void apply(const instruction &i) {
    if (i.direction == "forward") {
      horizontal_position += i.distance;
    } else if (i.direction == "down") {
      depth += i.distance;
    } else if (i.direction == "up") {
      depth -= i.distance;
    } else {
      throw std::runtime_error(std::string{"Invalid direction: "} +
                               i.direction);
    }
  }
};

std::istream &operator>>(std::istream &is, instruction &x) {
  return is >> x.direction >> x.distance;
}

auto part1(auto &in) {
  location l{};

  for (const auto i : read_vector<instruction>(in)) {
    l.apply(i);
  }

  return l.horizontal_position * l.depth;
}
} // namespace aoc2021::day2