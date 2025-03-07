// Has Subarray Sum
//
// Write a function, hasSubarraySum, that takes in a vector of numbers and a
// targetSum. The function should return a boolean indicating whether or not there
// exists a subarray of numbers that sums to the given target.
//
// A subarray is a consecutive series of one or more elements of the vector.
//
// Complexity:
// Time: O(n), where n is the size of the input vector. The algorithm iterates
// through the vector once and uses an unordered set to track the complementary sums.
// Space: O(n), where n is the size of the input vector, due to the unordered set storing prefix sums.

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

bool hasSubarraySum(const std::vector<int>& numbers, const int targetSum) {
  int total = 0;
  std::unordered_set<int> complementaries{0}; // starting with 0 for handling the case where the sum is directly the target

  for (const auto& num : numbers) {
    total += num;
    if (complementaries.count(total - targetSum)) {
      return true;
    }
    complementaries.insert(total);
  }

  return false;
}

int main() {
  assert(hasSubarraySum({1, 3, 1, 4, 3}, 8));         // -> true
  assert(!hasSubarraySum({1, 3, 1, 4, 3}, 2));        // -> false
  assert(hasSubarraySum({1, 3, 1, 1, 3}, 2));         // -> true
  assert(hasSubarraySum({5}, 5));                     // -> true
  assert(hasSubarraySum({4, 2, 5, 1, 5, -2, 8}, 9));  // -> true
  assert(!hasSubarraySum({4, 2, 5, 1, 5, -2, 8}, 10)); // -> false
  assert(hasSubarraySum({1, 1, 1, 1, 1, 1, 1, 1, 1}, 9)); // -> true
  
  std::cout << "All tests passed!\n";
  return 0;
}
