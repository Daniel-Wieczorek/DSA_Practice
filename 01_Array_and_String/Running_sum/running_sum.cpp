// Running Sum
//
// Write a function, runningSum, that takes in a vector of numbers. The function
// should return a new vector of the same length where each element contains the
// running sum up to that index of the original vector.
//
// For example, the i-th result should be the sum of all elements 0 to i:
//
// result[i] = numbers[0] + numbers[1] + numbers[2] + ... + numbers[i]

// Complexity:
// Time: O(n) where n is the length of the input vector.
// Space: O(n) for the resulting vector.

#include <cassert>
#include <iostream>
#include <vector>

std::vector<int> runningSum(const std::vector<int>& numbers) {
  std::vector<int> result{};
  int total{};
  for (const auto& num : numbers) {
    total += num;
    result.push_back(total);
  }
  return result;
}

void printResult(const std::vector<int>& input) {
  for (const auto& val : input) {
    std::cout << val << ",";
  }
  std::cout << "\n";
}

int main() {
  std::vector<int> result;

  result = runningSum({4, 2, 1, 6, 3, 6});
  printResult(result);
  assert((result == std::vector<int>{4, 6, 7, 13, 16, 22}));

  result = runningSum({10, 5, -2, 1, 1});
  printResult(result);
  assert((result == std::vector<int>{10, 15, 13, 14, 15}));

  result = runningSum({12, 88, 0, -50, 30, 2});
  printResult(result);
  assert((result == std::vector<int>{12, 100, 100, 50, 80, 82}));

  result = runningSum({2});
  printResult(result);
  assert((result == std::vector<int>{2}));

  std::cout << "All tests passed!\n";
  return 0;
}
