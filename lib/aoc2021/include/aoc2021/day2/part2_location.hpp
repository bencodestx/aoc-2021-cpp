#pragma once

#include "aoc2021/read_vector.hpp"
#include "instruction.hpp"

#include <range/v3/numeric/accumulate.hpp>

namespace aoc2021::day2 {

struct part2_location {
  int horizontal_position{};
  int aim{};
  int depth{};
};

part2_location operator+(const part2_location &l, const instruction &i) {
  if (i.direction == "forward") {
    return {.horizontal_position = l.horizontal_position + i.distance,
            .aim = l.aim,
            .depth = l.depth + i.distance * l.aim};
  } else if (i.direction == "down") {
    return {.horizontal_position = l.horizontal_position,
            .aim = l.aim + i.distance,
            .depth = l.depth};
  } else if (i.direction == "up") {
    return {.horizontal_position = l.horizontal_position,
            .aim = l.aim - i.distance,
            .depth = l.depth};
  }
  throw std::runtime_error(std::string{"Invalid direction: "} + i.direction);
}

} // namespace aoc2021::day2