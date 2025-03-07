// Merge Lists (https://www.structy.net/)
//
// Write a function, mergeLists, that takes in pointers to the heads of two
// sorted linked lists. The function should merge the two lists together into a
// single sorted linked list. The function should return a pointer to the head
// of the merged linked list.
//
// Do this in-place, by mutating the original Nodes.
//
// You may assume that both input lists are non-empty and contain increasing
// sorted numbers.
//
// Complexity:
// Time: O(n + m) where n and m are the lengths of the two input lists.
// Space: O(1) since we are mutating the original lists in-place without using
// extra space.

#include <cassert>
#include <iostream>

// Node structure definition
class Node {
 public:
  int val;
  Node* next;

  Node() : Node(0) {}
  explicit Node(int initialVal) : val{initialVal}, next{nullptr} {}
};

Node* mergeLists(Node* head1, Node* head2) {
  Node* dummy_head = new Node();
  Node* tail = dummy_head;

  Node* current1 = head1;
  Node* current2 = head2;

  // Merge both lists while both have remaining nodes
  while (current1 != nullptr && current2 != nullptr) {
    if (current1->val < current2->val) {
      tail->next = current1;
      current1 = current1->next;
    } else {
      tail->next = current2;
      current2 = current2->next;
    }
    tail = tail->next;
  }

  // Append the remaining nodes from either list
  if (current1 != nullptr) {
    tail->next = current1;
  } else if (current2 != nullptr) {
    tail->next = current2;
  }

  return dummy_head->next;
}

void test_mergeLists() {
  // Creating the first linked list
  Node a(5);
  Node b(7);
  Node c(10);
  Node d(12);
  Node e(20);
  Node f(28);
  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = &f;
  // 5 -> 7 -> 10 -> 12 -> 20 -> 28

  // Creating the second linked list
  Node q(6);
  Node r(8);
  Node s(9);
  Node t(25);
  q.next = &r;
  r.next = &s;
  s.next = &t;
  // 6 -> 8 -> 9 -> 25

  // Merging the two lists
  Node* merged = mergeLists(&a, &q);

  // Testing the merged result
  const int expected[] = {5, 6, 7, 8, 9, 10, 12, 20, 25, 28};
  Node* current = merged;
  for (int i = 0; current != nullptr; ++i, current = current->next) {
    assert(current->val == expected[i]);
  }

  // Creating new linked lists for another test
  Node g(5);
  Node h(7);
  Node i(10);
  Node j(12);
  Node k(20);
  Node l(28);
  g.next = &h;
  h.next = &i;
  i.next = &j;
  j.next = &k;
  k.next = &l;

  Node x(1);
  Node y(8);
  Node z(9);
  Node w(10);
  x.next = &y;
  y.next = &z;
  z.next = &w;
  // 1 -> 8 -> 9 -> 10

  // Merging the lists again
  merged = mergeLists(&g, &x);

  // Testing the merged result
  const int expected2[] = {1, 5, 7, 8, 9, 10, 10, 12, 20, 28};
  current = merged;
  for (int ii = 0; current != nullptr; ++ii, current = current->next) {
    assert(current->val == expected2[ii]);
  }

  std::cout << "All tests passed.\n";
}

int main() {
  test_mergeLists();
  return 0;
}
