#pragma once

#include "aoc2021/day4/bingo.hpp"

#include <istream>

namespace aoc2021::day4 {

auto part1(auto &in) {
  bingo_numbers numbers{};
  in >> numbers;
  bingo_cards cards{};
  in >> cards;
  auto end = std::begin(numbers);
  while (true) {
    for (const auto &card : cards) {
      if (is_winner(std::begin(numbers), end, card)) {
        return score_card(std::begin(numbers), end, card);
      }
    }
    ++end;
  }
}

} // namespace aoc2021::day4