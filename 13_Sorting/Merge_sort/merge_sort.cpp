// Merge Sort
//
// Merge sort is a divide-and-conquer algorithm that splits the input array
// into two halves, recursively sorts them, and then merges the sorted halves.
// It has a time complexity of O(n log n), making it one of the more efficient
// comparison-based sorting algorithms.
//
// Complexity:
// Time: O(n log n) where n is the number of elements in the array.
// Space: O(n) for the temporary array used during merging.

#include <cassert>
#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;

  std::vector<int> L(n1), R(n2);

  for (int i = 0; i < n1; i++) {
    L[i] = arr[left + i];
  }
  for (int i = 0; i < n2; i++) {
    R[i] = arr[mid + 1 + i];
  }

  // Merge the tmp arrays into the org
  int i = 0, j = 0, k = left;
  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

// Recursive function that implements merge sort
void mergeSort(std::vector<int>& arr, int left, int right) {
  if (left >= right) {
    return;
  }

  int mid = left + (right - left) / 2;

  // Sort the first and second halves
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);

  // Merge the sorted halves
  merge(arr, left, mid, right);
}

int main() {
  std::vector<int> arr;

  arr = {5, 2, 9, 1, 5, 6};
  mergeSort(arr, 0, arr.size() - 1);
  assert((arr == std::vector<int>{1, 2, 5, 5, 6, 9}));

  arr = {1, 2, 3, 4, 5};
  mergeSort(arr, 0, arr.size() - 1);
  assert((arr == std::vector<int>{1, 2, 3, 4, 5}));

  arr = {-3, -1, -4, 2, 0, -2};
  mergeSort(arr, 0, arr.size() - 1);
  assert((arr == std::vector<int>{-4, -3, -2, -1, 0, 2}));

  arr = {10};
  mergeSort(arr, 0, arr.size() - 1);
  assert((arr == std::vector<int>{10}));

  arr = {};
  mergeSort(arr, 0, arr.size() - 1);
  assert(arr.empty());

  std::cout << "All tests passed!\n";
  return 0;
}
