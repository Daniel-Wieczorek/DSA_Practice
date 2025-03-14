// Insertion Sort
//
// Insertion sort is a simple comparison-based sorting algorithm. It builds
// the sorted array one element at a time by repeatedly inserting the next
// element into the correct position within the already sorted portion of the
// array. While efficient for small data sets, its time complexity of O(n^2)
// makes it inefficient for larger arrays.
//
// Complexity:
// Time: O(n^2) in the worst case where n is the number of elements in the array.
// Space: O(1) since the sorting is done in-place.

#include <cassert>
#include <iostream>
#include <vector>

void insertionSort(std::vector<int>& arr) {
  for (int i = 1; i < arr.size(); i++) {
    int key = arr[i];
    int j = i - 1;

    // Move elements of arr[0..i-1], that are greater than key, to one position ahead
    // of their current position
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  std::vector<int> arr;

  // Test 1: Normal case
  arr = {12, 11, 13, 5, 6};
  insertionSort(arr);
  assert((arr == std::vector<int>{5, 6, 11, 12, 13}));

  // Test 2: Already sorted array
  arr = {1, 2, 3, 4, 5};
  insertionSort(arr);
  assert((arr == std::vector<int>{1, 2, 3, 4, 5}));

  // Test 3: Array with negative numbers
  arr = {-2, 1, 0, -1, -3};
  insertionSort(arr);
  assert((arr == std::vector<int>{-3, -2, -1, 0, 1}));

  // Test 4: Single-element array
  arr = {10};
  insertionSort(arr);
  assert((arr == std::vector<int>{10}));

  // Test 5: Empty array
  arr = {};
  insertionSort(arr);
  assert(arr.empty());

  std::cout << "All tests passed!\n";
  return 0;
}
