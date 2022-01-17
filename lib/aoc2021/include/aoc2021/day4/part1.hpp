#pragma once

#include "aoc2021/day4/bingo.hpp"

#include <istream>

namespace aoc2021::day4 {

auto part1(auto &in) {
  bingo_system bingo{};
  in >> bingo;
  const auto begin = std::begin(bingo.numbers);
  auto end = begin;
  while (true) {
    for (const auto &card : bingo.cards) {
      if (is_winner(begin, end, card)) {
        return score_card(begin, end, card);
      }
    }
    ++end;
  }
}

} // namespace aoc2021::day4