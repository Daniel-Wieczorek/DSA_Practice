// Palindrome Recursive (https://www.structy.net/)
//
// Write a function, palindrome, that takes in a string and returns a boolean
// indicating whether or not the string is the same forwards and backwards.
//
// You must solve this recursively.
//
// Complexity:
// Time: O(n^2) due to string slicing in reverseString function.
// Space: O(n) due to recursion depth and string storage.

#include <cassert>
#include <iostream>
#include <string>

std::string reverseString(const std::string& s) {
  if (s.empty()) {
    return "";
  }

  // Suboptimal as it leads to new string creation each time
  return *s.rbegin() + reverseString(s.substr(0, s.size() - 1));
}

bool palindrome(const std::string& s) { return reverseString(s) == s; }

int main() {
  assert(palindrome("pop"));      // -> true
  assert(palindrome("kayak"));    // -> true
  assert(!palindrome("pops"));    // -> false
  assert(!palindrome("boot"));    // -> false
  assert(palindrome("rotator"));  // -> true
  assert(!palindrome("abcbca"));  // -> false
  std::cout << "All tests passed!\n";
  return 0;
}
