// Fibonacci (https://www.structy.net/)
//
// Write a function, fibonacci, that takes in a number argument, n, and returns
// the n-th number of the Fibonacci sequence.
//
// The 0-th number of the sequence is 0.
//
// The 1-st number of the sequence is 1.
//
// To generate further numbers of the sequence, calculate the sum of previous
// two numbers.
//
// You must solve this recursively.
//
// Complexity:
// Time: O(2^n), exponential time due to redundant recursive calls. Dynamic
// programming arroach would be better here
//
// Space: O(n), due to the recursion stack depth.

#include <cassert>
#include <iostream>

int fibonacci(int n) {
  if (n == 0 || n == 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  assert(fibonacci(0) == 0);  // -> 0
  assert(fibonacci(1) == 1);  // -> 1
  assert(fibonacci(2) == 1);  // -> 1
  assert(fibonacci(3) == 2);  // -> 2
  assert(fibonacci(4) == 3);  // -> 3
  assert(fibonacci(5) == 5);  // -> 5
  std::cout << "All tests passed!\n";
  return 0;
}
