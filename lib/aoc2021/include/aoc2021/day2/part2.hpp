#pragma once

#include "aoc2021/read_vector.hpp"
#include "instruction.hpp"

namespace aoc2021::day2 {
struct location2 {
  int horizontal_position{};
  int aim{};
  int depth{};

  void apply(const instruction &i) {
    if (i.direction == "forward") {
      horizontal_position += i.distance;
      depth += i.distance * aim;
    } else if (i.direction == "down") {
      aim += i.distance;
    } else if (i.direction == "up") {
      aim -= i.distance;
    } else {
      throw std::runtime_error(std::string{"Invalid direction: "} +
                               i.direction);
    }
  }
};

auto part2(auto &in) {
  location2 l{};

  for (const auto i : read_vector<instruction>(in)) {
    l.apply(i);
  }

  return l.horizontal_position * l.depth;
}

} // namespace aoc2021::day2