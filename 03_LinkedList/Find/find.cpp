// Linked List Find (https://www.structy.net/)
//
// Write a function, linkedListFind, that takes in a pointer to the head of a
// linked list and a target value. The function should return a boolean
// indicating whether or not the linked list contains the target.
//
// Complexity:
// Time: O(n) where n is the number of nodes in the linked list, since we may
// need to traverse the entire list.
// Space: O(1) as we are using only a constant amount of extra space.

#include <cassert>
#include <iostream>
#include <string>

class Node {
 public:
  std::string val;
  Node* next;

  explicit Node(const std::string& initialVal)
      : val{initialVal}, next{nullptr} {}
};

bool linkedListFind(Node* head, const std::string& target) {
  Node* current = head;

  while (current != nullptr) {
    if (current->val == target) {
      return true;
    }
    current = current->next;
  }

  return false;
}

int main() {
  Node a("a");
  Node b("b");
  Node c("c");
  Node d("d");

  a.next = &b;
  b.next = &c;
  c.next = &d;

  // a -> b -> c -> d
  assert(linkedListFind(&a, "c"));   // 1 (true)
  assert(linkedListFind(&a, "d"));   // 1 (true)
  assert(!linkedListFind(&a, "q"));  // 0 (false)

  Node node1("jason");
  Node node2("leneli");

  node1.next = &node2;

  // jason -> leneli
  assert(linkedListFind(&node1, "jason"));  // 1 (true)

  Node node3("potato");
  // potato
  assert(linkedListFind(&node3, "potato"));  // 1 (true)

  std::cout << "All tests passed!\n";
  return 0;
}
