// Decompress Braces (https://www.structy.net/)
//
// Write a function, decompressBraces, that takes in a compressed string as an
// argument. The function should return the string decompressed.
//
// The compression format of the input string is 'n{subString}', where the
// subString within braces should be repeated n times.
//
// You may assume that every number n is guaranteed to be an integer between 1
// through 9.
//
// You may assume that the input is valid and the decompressed string will only
// contain alphabetic characters.

// Complexity:
// Time: O(n), where n is the length of the input string.
// Space: O(n), due to the usage of a stack storing substrings.

#include <cassert>
#include <cctype>
#include <iostream>
#include <stack>
#include <string>

void unwindStack(std::stack<std::string> &stack_data) {
  std::string repeat{};
  while (!isdigit(stack_data.top()[0])) {
    repeat = stack_data.top() + repeat;
    stack_data.pop();
  }

  int repetitions = std::stoi(stack_data.top());
  stack_data.pop();

  std::string result{};
  for (int i = 0; i < repetitions; ++i) {
    result += repeat;
  }

  stack_data.push(result);
}

std::string decompressBraces(const std::string &str) {
  std::stack<std::string> output{};
  for (const char &ch : str) {
    if (ch == '}') {
      unwindStack(output);
    } else if (isdigit(ch)) {
      output.push(std::string(1, ch));
    } else if (ch != '{') {
      output.push(std::string(1, ch));
    }
  }

  std::string result{};
  while (!output.empty()) {
    result = output.top() + result;
    output.pop();
  }

  return result;
}

int main() {
  assert(decompressBraces("2{q}3{tu}v") == "qqtututuv");
  assert(decompressBraces("ch3{ao}") == "chaoaoao");
  assert(decompressBraces("2{y3{o}}s") == "yoooyooos");
  assert(decompressBraces("z3{a2{xy}b}") == "zaxyxybaxyxybaxyxyb");
  assert(decompressBraces("2{3{r4{e}r}io}") ==
         "reeeerreeeerreeeerioreeeerreeeerreeeerio");
  assert(decompressBraces("go3{spinn2{ing}s}") ==
         "gospinningingsspinningingsspinningings");
  assert(decompressBraces("2{l2{if}azu}l") == "lififazulififazul");

  std::cout << "All tests passed!\n";
  return 0;
}
