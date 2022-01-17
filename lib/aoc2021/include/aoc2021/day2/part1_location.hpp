#pragma once

#include "aoc2021/day2/instruction.hpp"

#include <stdexcept>

namespace aoc2021::day2 {

struct part1_location {
  int horizontal_position{};
  int depth{};
};

part1_location operator+(const part1_location &l, const instruction &i) {
  if (i.direction == "forward") {
    return {.horizontal_position = l.horizontal_position + i.distance,
            .depth = l.depth};
  } else if (i.direction == "down") {
    return {.horizontal_position = l.horizontal_position,
            .depth = l.depth + i.distance};
  } else if (i.direction == "up") {
    return {.horizontal_position = l.horizontal_position,
            .depth = l.depth - i.distance};
  }
  throw std::runtime_error(std::string{"Invalid direction: "} + i.direction);
}

} // namespace aoc2021::day2