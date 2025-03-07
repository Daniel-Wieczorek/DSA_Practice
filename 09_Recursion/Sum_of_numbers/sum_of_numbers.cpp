// Sum Numbers Recursive (https://www.structy.net/)
//
// Write a function sumNumbersRecursive that takes in a vector of numbers and
// returns the sum of all the numbers in the vector. All elements will be
// integers. Solve this recursively.
//
// Complexity:
// Time: O(n) where n is the number of elements in the vector, since each
// element must be visited once recursively.
//
// Space: O(n) due to the recursion stack, which holds one frame per element
// in the vector.

#include <cassert>
#include <iostream>
#include <vector>

int sumNumbersRecursive(std::vector<int> numbers) {
  if (numbers.size() == 0) {
    return 0;
  }

  return numbers[0] + sumNumbersRecursive(
                          std::vector<int>(numbers.begin() + 1, numbers.end()));
}

int main() {
  assert(sumNumbersRecursive({5, 2, 9, 10}) == 26);               // -> 26
  assert(sumNumbersRecursive({1, -1, 1, -1, 1, -1, 1}) == 1);     // -> 1
  assert(sumNumbersRecursive({}) == 0);                           // -> 0
  assert(sumNumbersRecursive({1000, 0, 0, 0, 0, 0, 1}) == 1001);  // -> 1001
  assert(sumNumbersRecursive({700, 70, 7}) == 777);               // -> 777
  assert(sumNumbersRecursive({-10, -9, -8, -7, -6, -5, -4, -3, -2, -1}) ==
         -55);  // -> -55
  assert(sumNumbersRecursive({0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0}) == 0);  // -> 0
  std::cout << "All tests passed!\n";
  return 0;
}
