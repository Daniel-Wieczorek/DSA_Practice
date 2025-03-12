// Pair Product (https://www.structy.net/)
//
// Write a function, pairProduct, that takes in a vector of numbers and a target
// product as arguments. The function should return a std::array containing a
// pair of indices whose elements multiply to the given target. The indices
// returned must be unique.
//
// Be sure to return the indices, not the elements themselves.
//
// There is guaranteed to be one such pair whose product is the target.

// Complexity:
// Time: O(n), where n is the number of elements in the vector.
// Space: O(n), due to the unordered_map storing seen numbers.

#include <array>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

std::array<int, 2> pairProduct(const std::vector<int> &numbers, int target) {
  std::unordered_map<int, int> numbers_map{};

  for (size_t i = 0; i < numbers.size(); ++i) {
    if (target % numbers[i] == 0) {  // Ensure division is valid
      int complement = target / numbers[i];
      if (numbers_map.count(complement)) {
        return {numbers_map[complement], static_cast<int>(i)};
      }
    }
    numbers_map[numbers[i]] = static_cast<int>(i);
  }

  return {};  // This case is guaranteed not to occur per problem statement
}

int main() {
  assert((pairProduct({3, 2, 5, 4, 1}, 8) == std::array<int, 2>{1, 3}));
  assert((pairProduct({3, 2, 5, 4, 1}, 10) == std::array<int, 2>{1, 2}));
  assert((pairProduct({4, 7, 9, 2, 5, 1}, 5) == std::array<int, 2>{4, 5}));
  assert((pairProduct({4, 7, 9, 2, 5, 1}, 35) == std::array<int, 2>{1, 4}));
  assert((pairProduct({4, 6, 8, 2}, 16) == std::array<int, 2>{2, 3}));

  std::cout << "All tests passed!\n";
  return 0;
}
