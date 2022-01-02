#include <algorithm>
#include <vector>

namespace aoc2021::day1 {
auto part2(auto &in) {
  constexpr auto window_size = 3;

  int value;
  std::vector<int> values{};

  while (in >> value) {
    values.emplace_back(value);
  }

  size_t count{};
  for (auto it = std::cbegin(values); it != (std::cend(values) - window_size);
       ++it) {
    if (*(it + window_size) > *it) {
      ++count;
    }
  }

  return count;
}
} // namespace aoc2021::day1