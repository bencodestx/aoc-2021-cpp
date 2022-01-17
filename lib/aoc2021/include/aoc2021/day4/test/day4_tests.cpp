#include <gtest/gtest.h>

#include "aoc2021/day4/part1.hpp"

static constexpr auto sample =
    R"(7,4,9,5,11,17,23,2,0,14,21,24,10,16,13,6,15,25,12,22,18,20,8,19,3,26,1

22 13 17 11  0
 8  2 23  4 24
21  9 14 16  7
 6 10  3 18  5
 1 12 20 15 19

 3 15  0  2 22
 9 18 13 17  5
19  8  7 25 23
20 11 10 24  4
14 21 16 12  6

14 21 17 24  4
10 16 15  9 19
18  8 23 26 20
22 11 13  6  5
 2  0 12  3  7)";

namespace aoc2021::day4 {
TEST(Day4, Read_Numbers) {
  std::stringstream in{sample};
  bingo_numbers numbers{};
  in >> numbers;
  EXPECT_EQ(27, std::size(numbers));
}

TEST(Day4, Read_Cards) {
  std::stringstream in{sample};
  bingo_numbers numbers{};
  in >> numbers;
  bingo_cards cards{};
  in >> cards;
  EXPECT_EQ(3, std::size(cards));
  EXPECT_EQ(22, cards[0][0]);
  EXPECT_EQ(19, cards[0][24]);
  EXPECT_EQ(3, cards[1][0]);
  EXPECT_EQ(6, cards[1][24]);
  EXPECT_EQ(14, cards[2][0]);
  EXPECT_EQ(7, cards[2][24]);
}

TEST(Day4, No_Winners) {
  std::stringstream in{sample};
  bingo_numbers numbers{};
  in >> numbers;
  bingo_cards cards{};
  in >> cards;

  EXPECT_FALSE(
      is_winner(std::begin(numbers), std::begin(numbers) + 11, cards[0]));
  EXPECT_FALSE(
      is_winner(std::begin(numbers), std::begin(numbers) + 11, cards[1]));
  EXPECT_FALSE(
      is_winner(std::begin(numbers), std::begin(numbers) + 11, cards[2]));
}

TEST(Day4, One_Winner) {
  std::stringstream in{sample};
  bingo_numbers numbers{};
  in >> numbers;
  bingo_cards cards{};
  in >> cards;

  EXPECT_FALSE(
      is_winner(std::begin(numbers), std::begin(numbers) + 12, cards[0]));
  EXPECT_FALSE(
      is_winner(std::begin(numbers), std::begin(numbers) + 12, cards[1]));
  EXPECT_TRUE(
      is_winner(std::begin(numbers), std::begin(numbers) + 12, cards[2]));
}

TEST(Day4, Part1) {
  std::stringstream in{sample};

  EXPECT_EQ(4512, part1(in));
}
} // namespace aoc2021::day4