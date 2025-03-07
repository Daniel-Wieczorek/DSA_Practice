// Reverse String Recursive (https://www.structy.net/)
//
// Write a function, reverseString, that takes in a string as an argument. The
// function should return the string with its characters in reverse order. You
// must do this recursively.
//
// Complexity:
// Time: O(n) where n is the length of the string, as the string is being
// processed character by character.
//
// Space: O(n) due to the recursive call stack, as the function is called
// recursively for each character in the string.

#include <cassert>
#include <iostream>
#include <string>

std::string reverseString(const std::string& s) {
  static const size_t start_pos(0);
  static const size_t last_element(1);
  if (s.empty()) {
    return "";
  }

  return *(s.rbegin()) +
         reverseString(s.substr(start_pos, (s.size() - last_element)));
}

int main() {
  assert(reverseString("hello") == "olleh");          // -> "olleh"
  assert(reverseString("abcdefg") == "gfedcba");      // -> "gfedcba"
  assert(reverseString("stopwatch") == "hctawpots");  // -> "hctawpots"
  std::cout << "All tests passed!\n";
  return 0;
}
