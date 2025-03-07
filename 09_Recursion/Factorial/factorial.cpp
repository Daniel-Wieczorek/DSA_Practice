// Factorial (https://www.structy.net/)
//
// Write a function, factorial, that takes in a number n and returns the
// factorial of that number. The factorial of n is the product of all the
// positive numbers less than or equal to n. You must solve this recursively.
//
// For example, the factorial of 6 is:
//
// 6 * 5 * 4 * 3 * 2 * 1 = 720
//
// You can assume that n is a non-negative integer. Note that the factorial
// of 0 is defined to be 1 (wiki).
//
// Complexity:
// Time: O(n) because we make a recursive call n times until we reach the base
// case. Space: O(n) due to the recursive stack depth.

#include <cassert>
#include <iostream>

long factorial(int n) {
  if (n == 0) {
    return 1;
  }
  return (n * factorial(n - 1));
}

int main() {
  assert(factorial(3) == 6);                  // -> 6
  assert(factorial(6) == 720);                // -> 720
  assert(factorial(18) == 6402373705728000);  // -> 6402373705728000
  assert(factorial(1) == 1);                  // -> 1
  assert(factorial(13) == 6227020800);        // -> 6227020800
  std::cout << "All tests passed!\n";
  return 0;
}
