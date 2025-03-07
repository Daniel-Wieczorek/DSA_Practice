// Befitting Brackets (https://www.structy.net/)
//
// Write a function, befittingBrackets, that takes in a string as an argument.
// The function should return a boolean indicating whether or not the string
// contains correctly matched brackets.
//
// You may assume the string contains only characters: ( ) [ ] { }

// Complexity:
// Time: O(n), where n is the length of the string, as we process each character
// once. Space: O(n), in the worst case, when all opening brackets are pushed
// onto the stack.

#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

bool befittingBrackets(const std::string &str) {
  std::stack<char> parentheses{};
  const std::unordered_map<char, char> symbols{
      {'{', '}'}, {'[', ']'}, {'(', ')'}};

  for (const auto &ch : str) {
    if (symbols.count(ch)) {
      parentheses.push(ch);
    } else if (ch == ')' || ch == '}' || ch == ']') {
      if (parentheses.empty() || symbols.at(parentheses.top()) != ch) {
        return false;
      }
      parentheses.pop();
    }
  }

  return parentheses.empty();
}

int main() {
  assert(befittingBrackets("(){}[](())"));         // -> true
  assert(befittingBrackets("({[]})"));             // -> true
  assert(befittingBrackets("[][}") == false);      // -> false
  assert(befittingBrackets("{[]}({}") == false);   // -> false
  assert(befittingBrackets("[]{}(}[]") == false);  // -> false
  assert(befittingBrackets("[]{}()[]"));           // -> true
  assert(befittingBrackets("]{}") == false);       // -> false
  assert(befittingBrackets("") == true);           // -> true

  std::cout << "All tests passed!\n";
  return 0;
}
