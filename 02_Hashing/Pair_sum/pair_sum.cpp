// Pair Sum (https://www.structy.net/)
//
// Write a function, pairSum, that takes in a vector of numbers and a target sum
// as arguments. The function should return a std::array containing a pair of
// indices whose elements sum to the given target. The indices returned must be
// unique.
//
// Be sure to return the indices, not the elements themselves.
//
// There is guaranteed to be one such pair that sums to the target.

// Complexity:
// Time: O(n), where n is the number of elements in the vector.
// Space: O(n), due to the use of an unordered_map for storing seen elements.

#include <array>
#include <cassert>
#include <iostream>
#include <unordered_map>
#include <vector>

std::array<int, 2> pairSum(const std::vector<int>& numbers, int target) {
  std::unordered_map<int, int> seen;
  for (int i = 0; i < numbers.size(); ++i) {
    int complement = target - numbers[i];
    if (seen.count(complement)) {
      return {seen[complement], i};
    }
    seen[numbers[i]] = i;
  }
  throw std::runtime_error(
      "No valid pair found");  // Should never happen as per problem statement
}

int main() {
  assert((pairSum({3, 2, 5, 4, 1}, 8) == std::array<int, 2>{0, 2}));
  assert((pairSum({4, 7, 9, 2, 5, 1}, 5) == std::array<int, 2>{0, 5}));
  assert((pairSum({4, 7, 9, 2, 5, 1}, 3) == std::array<int, 2>{3, 5}));
  assert((pairSum({1, 6, 7, 2}, 13) == std::array<int, 2>{1, 2}));
  assert((pairSum({9, 9}, 18) == std::array<int, 2>{0, 1}));
  assert((pairSum({6, 4, 2, 8}, 12) == std::array<int, 2>{1, 3}));

  std::cout << "All tests passed!\n";
  return 0;
}
