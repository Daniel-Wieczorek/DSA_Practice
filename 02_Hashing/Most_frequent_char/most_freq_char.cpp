// Most Frequent Character (https://www.structy.net/)
//
// Write a function, mostFrequentChar, that takes in a string as an argument.
// The function should return the most frequent character of the string. If
// there are ties, return the character that appears earlier in the string.
//
// You can assume that the input string is non-empty.

// Complexity:
// Time: O(n), where n is the length of the string. We traverse the string
// twice: once for counting and once for finding the most frequent character.
//
// Space: O(1), since we store character counts in an unordered_map with at most
// 256 ASCII characters, which is constant space.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

char mostFrequentChar(const std::string &s) {
  std::unordered_map<char, int> count{};

  // Count occurrences of each character
  for (const auto &ch : s) {
    ++count[ch];
  }

  char best = s[0];  // Initialize with the first character
  std::for_each(s.begin(), s.end(), [&best, &count](const char &ch) {
    if (count[ch] > count[best]) {
      best = ch;
    }
  });

  return best;
}

int main() {
  assert(mostFrequentChar("bookeeper") == 'e');      // -> 'e'
  assert(mostFrequentChar("david") == 'd');          // -> 'd'
  assert(mostFrequentChar("abby") == 'b');           // -> 'b'
  assert(mostFrequentChar("mississippi") == 'i');    // -> 'i'
  assert(mostFrequentChar("potato") == 'o');         // -> 'o'
  assert(mostFrequentChar("eleventennine") == 'e');  // -> 'e'

  std::cout << "All tests passed!\n";
  return 0;
}
