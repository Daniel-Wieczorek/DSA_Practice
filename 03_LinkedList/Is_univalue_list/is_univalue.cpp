// Is Univalue List (https://www.structy.net/)
//
// Write a function, isUnivalueList, that takes in a pointer to the head of a
// linked list as an argument. The function should return a boolean indicating
// whether or not the linked list contains exactly one unique value.
//
// You may assume that the input list is non-empty.
//
// Complexity:
// Time: O(n) where n is the number of nodes in the linked list, as we need to
// traverse the entire list to check for univalue condition.
//
// Space: O(1) as we only use a few extra pointers regardless of the list size.

#include <cassert>
#include <iostream>

class Node {
 public:
  int val;
  Node* next;

  explicit Node(int initialVal) : val{initialVal}, next{nullptr} {}
};

bool isUnivalueList(Node* head) {
  Node* current = head;
  while (current != nullptr) {
    if (current->val != head->val) {
      return false;
    }
    current = current->next;
  }
  return true;
}

int main() {
  Node a(7);
  Node b(7);
  Node c(7);

  a.next = &b;
  b.next = &c;

  // 7 -> 7 -> 7
  assert(isUnivalueList(&a));  // 1 (true)

  Node d(7);
  Node e(7);
  Node f(4);

  d.next = &e;
  e.next = &f;

  // 7 -> 7 -> 4
  assert(!isUnivalueList(&d));  // 0 (false)

  Node u(2);
  Node v(2);
  Node w(2);
  Node x(2);
  Node y(2);

  u.next = &v;
  v.next = &w;
  w.next = &x;
  x.next = &y;

  // 2 -> 2 -> 2 -> 2 -> 2
  assert(isUnivalueList(&u));  // 1 (true)

  Node z(42);
  // 42
  assert(isUnivalueList(&z));  // 1 (true)

  Node p(2);
  Node q(2);
  Node r(3);
  Node s(3);
  Node t(2);

  p.next = &q;
  q.next = &r;
  r.next = &s;
  s.next = &t;

  // 2 -> 2 -> 3 -> 3 -> 2
  assert(!isUnivalueList(&p));  // 0 (false)

  std::cout << "All tests passed!\n";
  return 0;
}
