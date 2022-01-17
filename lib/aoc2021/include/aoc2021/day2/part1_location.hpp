#pragma once

#include "aoc2021/day2/instruction.hpp"

#include <stdexcept>

namespace aoc2021::day2 {

struct part1_location {
  int horizontal_position{};
  int depth{};

  part1_location forward(const auto distance) const {
    return {.horizontal_position = horizontal_position + distance,
            .depth = depth};
  }

  part1_location down(const auto distance) const {
    return {.horizontal_position = horizontal_position,
            .depth = depth + distance};
  }

  part1_location up(const auto distance) const {
    return {.horizontal_position = horizontal_position,
            .depth = depth - distance};
  }
};

part1_location operator+(const part1_location &l, const instruction &i) {
  return i.apply_to_location(l);
}

} // namespace aoc2021::day2