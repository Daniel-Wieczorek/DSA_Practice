// Five Sort (https://www.structy.net/)
//
// Write a function, fiveSort, that takes in a vector of numbers as an argument.
// The function should rearrange elements of the vector such that all 5s appear
// at the end. Your function should perform this operation in-place by mutating
// the original vector. The function should return the vector.
//
// Elements that are not 5 can appear in any order in the output, as long as all
// 5s are at the end of the vector.
//
// Complexity:
// Time: O(n) where n is the number of elements in the vector. The function
// performs a single pass through the vector with a linear time complexity.
//
// Space: O(1) since the operation is performed in-place without requiring extra
// space proportional to the input size.

#include <cassert>
#include <iostream>
#include <vector>

std::vector<int>& fiveSort(std::vector<int>& numbers) {
  size_t j = numbers.size() - 1;
  size_t i = 0;
  while (i <= j) {
    if (numbers[j] == 5) {
      --j;
      continue;
    }

    if (numbers[i] != 5) {
      ++i;
    } else {
      numbers[i] = numbers[j];
      numbers[j] = 5;
    }
  }

  return numbers;
}

int main() {
  std::vector<int> numbers1{12, 5, 1, 5, 12, 7};
  fiveSort(numbers1);
  assert((numbers1 == std::vector<int>{12, 7, 1, 12, 5, 5}));

  std::vector<int> numbers2{5, 2, 5, 6, 5, 1, 10, 2, 5, 5};
  fiveSort(numbers2);
  assert((numbers2 == std::vector<int>{2, 2, 10, 6, 1, 5, 5, 5, 5, 5}));

  std::vector<int> numbers3{5, 5, 5, 1, 1, 1, 4};
  fiveSort(numbers3);
  assert((numbers3 == std::vector<int>{4, 1, 1, 1, 5, 5, 5}));

  std::vector<int> numbers4{5, 5, 6, 5, 5, 5, 5};
  fiveSort(numbers4);
  assert((numbers4 == std::vector<int>{6, 5, 5, 5, 5, 5, 5}));

  std::vector<int> numbers5{5, 1, 2, 5, 5, 3, 2, 5, 1, 5, 5, 5, 4, 5};
  fiveSort(numbers5);
  assert(
      (numbers5 == std::vector<int>{4, 1, 2, 1, 2, 3, 5, 5, 5, 5, 5, 5, 5, 5}));

  std::cout << "All tests passed!\n";
  return 0;
}
