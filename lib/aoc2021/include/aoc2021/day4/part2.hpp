#pragma once

#include "aoc2021/day4/bingo.hpp"

#include <istream>

namespace aoc2021::day4 {

auto part2(auto &in) {
  bingo_numbers numbers{};
  in >> numbers;
  bingo_cards cards{};
  in >> cards;
  auto end = std::begin(numbers);
  while (std::size(cards) > 1) {
    std::erase_if(cards, [&](const auto &card) {
      return is_winner(std::begin(numbers), end, card);
    });
    ++end;
  }
  while (not is_winner(std::begin(numbers), end, cards[0])) {
    ++end;
  }
  return score_card(std::begin(numbers), end, cards[0]);
}

} // namespace aoc2021::day4