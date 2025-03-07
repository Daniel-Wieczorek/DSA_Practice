// Nesting Score (https://www.structy.net/)
//
// Write a function, nestingScore, that takes in a string of brackets as an
// argument. The function should return the score of the string according to
// the following rules:
//
// - "[]" is worth 1 point.
// - "XY" is worth m + n points where X, Y are substrings of well-formed
//   brackets and m, n are their respective scores.
// - "[S]" is worth 2 * k points where S is a substring of well-formed brackets
//   and k is the score of that substring.
//
// You may assume that the input only contains well-formed square brackets.

// Complexity:
// Time: O(n), where n is the length of the input string.
// Space: O(n) in the worst case due to stack usage.

#include <cassert>
#include <iostream>
#include <stack>

void incrementTopValue(std::stack<int>& stack, int val) {
  int current_val = stack.top();
  stack.pop();
  current_val += val;
  stack.push(current_val);
}

int nestingScore(const std::string& str) {
  std::stack<int> stack;
  stack.push(0);

  for (const char& ch : str) {
    if (ch == '[') {
      stack.push(0);
    } else {
      int popped = stack.top();
      stack.pop();
      if (popped == 0) {
        incrementTopValue(stack, 1);
      } else {
        incrementTopValue(stack, popped * 2);
      }
    }
  }
  return stack.top();
}

int main() {
  assert(nestingScore("[]") == 1);                    // -> 1
  assert(nestingScore("[][][]") == 3);                // -> 3
  assert(nestingScore("[[]]") == 2);                  // -> 2
  assert(nestingScore("[[][]]") == 4);                // -> 4
  assert(nestingScore("[[][][]]") == 6);              // -> 6
  assert(nestingScore("[[][]][]") == 5);              // -> 5
  assert(nestingScore("[][[][]][[]]") == 7);          // -> 7
  assert(nestingScore("[[[[[[[][]]]]]]][]") == 129);  // -> 129
  std::cout << "All tests passed!\n";
  return 0;
}
