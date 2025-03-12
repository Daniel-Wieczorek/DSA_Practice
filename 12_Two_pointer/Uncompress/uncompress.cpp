// Uncompress (https://www.structy.net/)
//
// Write a function, uncompress, that takes in a string as an argument. The
// input string will be formatted into multiple groups according to the
// following pattern:
//
// <number><char>
//
// for example, '2c' or '3a'.
// The function should return an uncompressed version of the string where each
// 'char' of a group is repeated 'number' times consecutively. You may assume
// that the input string is well-formed according to the previously mentioned
// pattern.

// Complexity:
// Time: O(n * m) where n is the number of groups and m is the maximum number
// for any group. Space: O(n * m) since the output string stores the expanded
// version of the input.

#include <cassert>
#include <cctype>
#include <iostream>
#include <string>

std::string uncompress(const std::string &s) {
  std::string number{};
  std::string out_str{};
  for (const unsigned char &character : s) {
    if (std::isdigit(character)) {
      number += character;
    } else {
      out_str.append(static_cast<std::size_t>(std::stoi(number)), character);
      number.clear();
    }
  }
  return out_str;
}

int main() {
  assert(uncompress("2c3a1t") == "ccaaat");    // -> "ccaaat"
  assert(uncompress("4s2b") == "ssssbb");      // -> "ssssbb"
  assert(uncompress("2p1o5p") == "ppoppppp");  // -> "ppoppppp"
  assert(uncompress("3n12e2z") ==
         "nnneeeeeeeeeeeezz");  // -> "nnneeeeeeeeeeeezz"
  assert(uncompress("127y") ==
         std::string(127, 'y'));  // -> "yyyy...y" (127 times)

  std::cout << "All tests passed!\n";
  return 0;
}
