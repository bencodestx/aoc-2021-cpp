namespace aoc2021::day1 {
auto part1(auto &in) {
  int previous, current;
  size_t count{};

  in >> previous;
  while (in >> current) {
    if (current > previous) {
      ++count;
    }
    previous = current;
  }

  return count;
}
} // namespace aoc2021::day1