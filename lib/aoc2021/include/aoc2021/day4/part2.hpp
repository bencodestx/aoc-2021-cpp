#pragma once

#include "aoc2021/day4/bingo.hpp"

#include <istream>

namespace aoc2021::day4 {

auto part2(auto &in) {
  bingo_system bingo{};
  in >> bingo;
  const auto begin = std::begin(bingo.numbers);
  auto end = begin;
  while (std::size(bingo.cards) > 1) {
    std::erase_if(bingo.cards, [&](const auto &card) {
      return is_winner(begin, end, card);
    });
    ++end;
  }
  const auto &last_card = bingo.cards.front();
  while (not is_winner(begin, end, last_card)) {
    ++end;
  }
  return score_card(begin, end, last_card);
}

} // namespace aoc2021::day4