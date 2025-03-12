// Intersection (https://www.structy.net/)
//
// Write a function, intersection, that takes in two vectors, a and b, as
// arguments. The function should return a new vector containing elements that
// are in both of the two vectors.
//
// You may assume that each input vector does not contain duplicate elements.
//
// Complexity:
// Time: O(n + m), where n is the size of vector a and m is the size of vector
// b. Space: O(m), where m is the size of vector b due to the unordered_set.

#include <algorithm>
#include <cassert>
#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> intersection(const std::vector<int>& a,
                              const std::vector<int>& b) {
  std::unordered_set<int> vec_map{b.begin(), b.end()};
  std::vector<int> result{};
  std::copy_if(a.begin(), a.end(), std::back_inserter(result),
               [&vec_map](int num) { return vec_map.count(num); });
  return result;
}

int main() {
  // Test cases
  std::vector<int> a1{4, 2, 1, 6};
  std::vector<int> b1{3, 6, 9, 2, 10};
  std::vector<int> result1 = intersection(a1, b1);
  assert((result1 == std::vector<int>{2, 6}));  // -> [2, 6]

  std::vector<int> a2{2, 4, 6};
  std::vector<int> b2{4, 2};
  std::vector<int> result2 = intersection(a2, b2);
  assert((result2 == std::vector<int>{2, 4}));  // -> [2, 4]

  std::vector<int> a3{4, 2, 1};
  std::vector<int> b3{1, 2, 4, 6};
  std::vector<int> result3 = intersection(a3, b3);
  assert((result3 == std::vector<int>{4, 2, 1}));  // -> [4, 2, 1]

  std::vector<int> a4{0, 1, 2};
  std::vector<int> b4{10, 11};
  std::vector<int> result4 = intersection(a4, b4);
  assert((result4.empty()));  // -> []

  std::cout << "All tests passed!\n";
  return 0;
}
