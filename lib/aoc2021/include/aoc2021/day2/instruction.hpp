#pragma once

#include <istream>
#include <string>

namespace aoc2021::day2 {

struct instruction {
  std::string direction{};
  int distance{};

  template <typename T> auto apply_to_location(const T &l) const {
    if (direction == "forward") {
      return l.forward(distance);
    } else if (direction == "down") {
      return l.down(distance);
    } else if (direction == "up") {
      return l.up(distance);
    }
    throw std::runtime_error(std::string{"Invalid direction: "} + direction);
  }
};

std::istream &operator>>(std::istream &is, instruction &x) {
  return is >> x.direction >> x.distance;
}

} // namespace aoc2021::day2
