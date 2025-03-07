// Sum List (https://www.structy.net/)
//
// Write a function, sumList, that takes in a pointer to the head of a linked
// list containing numbers as an argument. The function should return the total
// sum of all values in the linked list.
//
// Complexity:
// Time: O(n) where n is the number of nodes in the linked list.
// Space: O(1) as the space used does not depend on the size of the list.

#include <cassert>
#include <iostream>

class Node {
 public:
  int val;
  Node* next;

  explicit Node(int initialVal) : val{initialVal}, next{nullptr} {}
};

int sumList(Node* head) {
  int sum(0);
  Node* current = head;
  while (current != nullptr) {
    sum += current->val;
    current = current->next;
  }

  return sum;
}

int main() {
  Node a(2);
  Node b(8);
  Node c(3);
  Node d(-1);
  Node e(7);

  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;

  // 2 -> 8 -> 3 -> -1 -> 7
  assert(sumList(&a) == 19);  // -> 19

  Node x(38);
  Node y(4);

  x.next = &y;

  // 38 -> 4
  assert(sumList(&x) == 42);  // -> 42

  Node z(100);

  // 100
  assert(sumList(&z) == 100);  // -> 100

  std::cout << "All tests passed!\n";
  return 0;
}
