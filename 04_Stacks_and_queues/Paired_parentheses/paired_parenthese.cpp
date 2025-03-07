// Paired Parentheses (https://www.structy.net/)
//
// Write a function, pairedParentheses, that takes in a string as an argument.
// The function should return a boolean indicating whether or not the string has
// well-formed parentheses.
//
// You may assume the string contains only alphabetic characters, '(' or ')'.

// Complexity:
// Time: O(n), where n is the length of the string.
// Space: O(n) in the worst case if all characters are open parentheses.

#include <cassert>
#include <iostream>
#include <stack>
#include <string>

bool pairedParentheses(const std::string& str) {
  std::stack<char> parentheses{};
  for (const auto& ch : str) {
    if (ch == '(') {
      parentheses.push(ch);
    } else if (ch == ')') {
      if (parentheses.empty()) {
        return false;
      }
      parentheses.pop();
    }
  }
  return parentheses.empty();
}

int main() {
  assert(pairedParentheses("(david)((abby))"));          // -> true
  assert(pairedParentheses("()rose(jeff") == false);     // -> false
  assert(pairedParentheses(")(") == false);              // -> false
  assert(pairedParentheses("()"));                       // -> true
  assert(pairedParentheses("(((potato())))"));           // -> true
  assert(pairedParentheses("(())(water)()"));            // -> true
  assert(pairedParentheses("(())(water()()") == false);  // -> false
  assert(pairedParentheses(""));                         // -> true
  assert(pairedParentheses("))()") == false);            // -> false
  std::cout << "All tests passed!\n";
  return 0;
}
