// Sum of Lengths (https://www.structy.net/)
//
// Write a function sumOfLengths that takes in an array of strings and returns
// the total length of the strings. You must solve this recursively.
//
// Complexity:
// Time: O(n) where n is the number of strings in the input array.
// Space: O(n) due to the recursive call stack, where n is the number of
// strings.

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

int sumOfLengths(std::vector<std::string> strings) {
  if (strings.empty()) {
    return 0;
  }

  return strings[0].length() + sumOfLengths(std::vector<std::string>(
                                   strings.begin() + 1, strings.end()));
}

int main() {
  assert(sumOfLengths({"goat", "cat", "purple"}) == 13);                // -> 13
  assert(sumOfLengths({"bike", "at", "pencils", "phone"}) == 18);       // -> 18
  assert(sumOfLengths({}) == 0);                                        // -> 0
  assert(sumOfLengths({"", " ", "  ", "   ", "    ", "     "}) == 15);  // -> 15
  std::cout << "All tests passed!\n";
  return 0;
}
