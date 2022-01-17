#pragma once

#include "aoc2021/read_vector.hpp"

#include <array>
#include <istream>
#include <sstream>
#include <string>
#include <vector>

namespace aoc2021::day4 {
static constexpr size_t bingo_size{5};
using bingo_numbers = std::vector<unsigned>;
using bingo_card = std::array<unsigned, bingo_size * bingo_size>;
using bingo_cards = std::vector<bingo_card>;

struct bingo_system {
  bingo_numbers numbers{};
  bingo_cards cards{};
};

std::istream &operator>>(std::istream &is, bingo_numbers &numbers) {
  std::string line;
  std::getline(is, line);
  for (auto &c : line) {
    if (c == ',') {
      c = ' ';
    }
  }
  std::stringstream ss{line};
  numbers = read_vector<unsigned>(ss);
  return is;
}

std::istream &operator>>(std::istream &is, bingo_card &card) {
  for (auto &number : card) {
    is >> number;
  }
  return is;
}

std::istream &operator>>(std::istream &is, bingo_cards &cards) {
  bingo_card card{};
  while (is >> card) {
    cards.emplace_back(card);
  }
  return is;
}

std::istream &operator>>(std::istream &is, bingo_system &system) {
  return (is >> system.numbers >> system.cards);
}

auto is_number_called(const auto begin, const auto end, const auto number) {
  return end != std::find(begin, end, number);
}

auto is_row_winner(const auto begin, const auto end, const auto &card) {
  for (size_t row = 0; row < bingo_size; ++row) {
    size_t count{0};
    for (size_t col = 0; col < bingo_size; ++col) {
      if (is_number_called(begin, end, card[row * bingo_size + col])) {
        ++count;
      }
    }
    if (bingo_size == count) {
      return true;
    }
  }
  return false;
}

auto is_col_winner(const auto begin, const auto end, const auto &card) {
  for (size_t col = 0; col < bingo_size; ++col) {
    size_t count{0};
    for (size_t row = 0; row < bingo_size; ++row) {
      if (is_number_called(begin, end, card[row * bingo_size + col])) {
        ++count;
      }
    }
    if (bingo_size == count) {
      return true;
    }
  }
  return false;
}

auto is_winner(const auto begin, const auto end, const auto &card) {
  return is_row_winner(begin, end, card) or is_col_winner(begin, end, card);
}

auto score_card(const auto begin, const auto end, const auto &card) {
  size_t sum{};
  for (const auto number : card) {
    if (not is_number_called(begin, end, number)) {
      sum += number;
    }
  }
  return sum * *(end - 1);
}

} // namespace aoc2021::day4