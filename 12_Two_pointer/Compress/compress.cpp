// Compress (https://www.structy.net/)
//
// Write a function, compress, that takes in a string as an argument. The
// function should return a compressed version of the string where consecutive
// occurrences of the same characters are compressed into the number of
// occurrences followed by the character. Single character occurrences should
// not be changed.
//
// 'aaa' compresses to '3a'
// 'cc' compresses to '2c'
// 't' should remain as 't'
// You can assume that the input only contains alphabetic characters.
//
// Complexity:
// Time: O(n) where n is the length of the string.
// Space: O(n) since we store the compressed result in a new string.

#include <cassert>
#include <iostream>
#include <string>

std::string compress(std::string s) {
  std::string out_str = {};
  for (size_t j = 0, i = 0; j < s.length(); ++j) {
    if (j + 1 == s.length() || s[j] != s[j + 1]) {  // Handle the last character
      int num = j - i + 1;
      out_str +=
          (num == 1) ? std::string(1, s[i]) : (std::to_string(num) + s[i]);
      i = j + 1;
    }
  }
  return out_str;
}

int main() {
  // Test cases
  assert(compress("ccaaatsss") == "2c3at3s");          // -> "2c3at3s"
  assert(compress("ssssbbz") == "4s2bz");              // -> "4s2bz"
  assert(compress("ppoppppp") == "2po5p");             // -> "2po5p"
  assert(compress("nnneeeeeeeeeeeezz") == "3n12e2z");  // -> "3n12e2z"

  std::cout << "All tests passed!\n";
  return 0;
}
