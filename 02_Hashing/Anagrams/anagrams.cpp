// Anagrams (https://www.structy.net/)
//
// Write a function, anagrams, that takes in two strings as arguments. The
// function should return a boolean indicating whether or not the strings are
// anagrams. Anagrams are strings that contain the same characters, but in any
// order.

// Complexity:
// Time: O(n + m) where n is length of the first string and m is length of the
// second string.

// Space: O(k) where k is number of ASCII characters what is const so actually
// that will be O(1).

#include <cassert>
#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<char, int> CountChars(const std::string& s1) {
  std::unordered_map<char, int> count{};
  for (const auto& ch : s1) {
    ++count[ch];
  }
  return count;
}

bool anagrams(const std::string& s1, const std::string& s2) {
  return CountChars(s1) == CountChars(s2);
}

int main() {
  assert(anagrams("restful", "fluster"));            // -> true
  assert(anagrams("cats", "tocs") == false);         // -> false
  assert(anagrams("monkeyswrite", "newyorktimes"));  // -> true
  assert(anagrams("paper", "reapa") == false);       // -> false
  assert(anagrams("elbow", "below"));                // -> true
  assert(anagrams("tax", "taxi") == false);          // -> false
  assert(anagrams("taxi", "tax") == false);          // -> false
  assert(anagrams("night", "thing"));                // -> true
  assert(anagrams("abbc", "aabc") == false);         // -> false
  assert(anagrams("po", "popp") == false);           // -> false
  std::cout << "All tests passed!\n";
  return 0;
}