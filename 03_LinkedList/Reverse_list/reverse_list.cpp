// Reverse List (https://www.structy.net/)
//
// Write a function, reverseList, that takes in a pointer to the head of a
// linked list as an argument. The function should reverse the order of the
// nodes in the linked list in-place and return the new head of the reversed
// linked list.
//
// Complexity:
// Time: O(n), where n is the number of nodes in the linked list.
// Space: O(1), since the reversal is done in-place with no extra space used.

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

Node* reverseList(Node* head) {
  Node* current = head;
  Node* previous = nullptr;

  while (current != nullptr) {
    Node* next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }

  return previous;
}

int main() {
  // Test case 1
  Node a("a");
  Node b("b");
  Node c("c");
  Node d("d");
  Node e("e");
  Node f("f");

  a.next = &b;
  b.next = &c;
  c.next = &d;
  d.next = &e;
  e.next = &f;

  // a -> b -> c -> d -> e -> f
  Node* reversedHead1 = reverseList(&a);
  assert(reversedHead1->val == "f");
  assert(reversedHead1->next->val == "e");
  assert(reversedHead1->next->next->val == "d");
  assert(reversedHead1->next->next->next->val == "c");
  assert(reversedHead1->next->next->next->next->val == "b");
  assert(reversedHead1->next->next->next->next->next->val == "a");

  // Test case 2
  Node x("x");
  Node y("y");

  x.next = &y;

  // x -> y
  Node* reversedHead2 = reverseList(&x);
  assert(reversedHead2->val == "y");
  assert(reversedHead2->next->val == "x");

  std::cout << "All tests passed!\n";
  return 0;
}
