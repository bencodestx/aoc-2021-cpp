#pragma once

#include "aoc2021/read_vector.hpp"
#include "instruction.hpp"

#include <range/v3/numeric/accumulate.hpp>

namespace aoc2021::day2 {

struct part2_location {
  int horizontal_position{};
  int aim{};
  int depth{};

  part2_location forward(const auto distance) const {
    return {.horizontal_position = horizontal_position + distance,
            .aim = aim,
            .depth = depth + distance * aim};
  }

  part2_location down(const auto distance) const {
    return {.horizontal_position = horizontal_position,
            .aim = aim + distance,
            .depth = depth};
  }

  part2_location up(const auto distance) const {
    return {.horizontal_position = horizontal_position,
            .aim = aim - distance,
            .depth = depth};
  }
};

part2_location operator+(const part2_location &l, const instruction &i) {
  return i.apply_to_location(l);
}

} // namespace aoc2021::day2