// Longest Streak (https://www.structy.net/)
//
// Write a function, longestStreak, that takes in a pointer to the head of a
// linked list as an argument. The function should return the length of the
// longest consecutive streak of the same value within the list.
//
// Complexity:
// Time: O(n) where n is the number of nodes in the linked list.
// Space: O(1) since only a few extra variables are used for tracking the
// longest streak.

#include <cassert>
#include <iostream>

class Node {
 public:
  int val;
  Node* next;

  explicit Node(int initialVal) : val{initialVal}, next{nullptr} {}
};

int longestStreak(Node* head) {
  Node* current = head;
  int max(0);
  int max_current(0);

  if (head == nullptr) {
    return 0;
  }

  int start = head->val;
  while (current != nullptr) {
    if (current->val == start) {
      ++max_current;
    } else {
      max_current = 1;
      start = current->val;
    }

    max = (max_current > max) ? max_current : max;
    current = current->next;
  }

  return max;
}

int main() {
  // Test 1
  Node a(5);
  Node b(5);
  Node c(7);
  Node d(7);
  Node e(7);
  Node f(6);

  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = &f;

  // 5 -> 5 -> 7 -> 7 -> 7 -> 6
  assert(longestStreak(&a) == 3);  // Expected output: 3

  // Test 2
  Node a2(3);
  Node b2(3);
  Node c2(3);
  Node d2(3);
  Node e2(9);
  Node f2(9);

  a2.next = &b2;
  b2.next = &c2;
  c2.next = &d2;
  d2.next = &e2;
  e2.next = &f2;

  // 3 -> 3 -> 3 -> 3 -> 9 -> 9
  assert(longestStreak(&a2) == 4);  // Expected output: 4

  // Test 3
  Node a3(9);
  Node b3(9);
  Node c3(1);
  Node d3(9);
  Node e3(9);
  Node f3(9);

  a3.next = &b3;
  b3.next = &c3;
  c3.next = &d3;
  d3.next = &e3;
  e3.next = &f3;

  // 9 -> 9 -> 1 -> 9 -> 9 -> 9
  assert(longestStreak(&a3) == 3);  // Expected output: 3

  // Test 4
  Node a4(5);
  Node b4(5);

  a4.next = &b4;

  // 5 -> 5
  assert(longestStreak(&a4) == 2);  // Expected output: 2

  // Test 5
  Node a5(4);

  // 4
  assert(longestStreak(&a5) == 1);  // Expected output: 1

  std::cout << "All tests passed!\n";
  return 0;
}
