// Remove Node (https://www.structy.net/)
//
// Write a function, removeNode, that takes in a pointer to the head of a linked
// list and a target value as arguments. The function should delete the node
// containing the target value from the linked list and return the head of the
// resulting linked list. If the target appears multiple times in the linked
// list, only remove the first instance of the target in the list.
//
// Do this in-place. You do not need to dynamically deallocate the memory with
// delete, just reassign next pointers correctly.
//
// You may assume that the input list is non-empty.
//
// You may assume that the input list contains the target.
//
// Complexity:
// Time: O(n), where n is the number of nodes in the linked list.
// Space: O(1), as we're modifying the list in place and using only a constant
// amount of extra space.

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

Node* removeNode(Node* head, const std::string& targetVal) {
  if (head->val == targetVal) {
    return head->next;
  }

  Node* current = head;
  Node* previous = nullptr;

  while (current != nullptr) {
    if (current->val == targetVal) {
      // Remove element
      previous->next = current->next;
      break;
    }
    previous = current;
    current = current->next;
  }

  return head;
}

int main() {
  // Test 1: a -> b -> c -> d -> e -> f
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

  Node* head = removeNode(&a, "c");
  assert(head->next->next->val == "d");  // -> a -> b -> d -> e -> f

  // Test 2: x -> y -> z
  Node x("x");
  Node y("y");
  Node z("z");

  x.next = &y;
  y.next = &z;

  head = removeNode(&x, "z");
  assert(head->next->val == "y");  // -> x -> y

  // Test 3: q -> r -> s
  Node q("q");
  Node r("r");
  Node s("s");

  q.next = &r;
  r.next = &s;

  head = removeNode(&q, "q");
  assert(head->val == "r");  // -> r -> s

  // Test 4: h -> i -> j -> i
  Node node1("h");
  Node node2("i");
  Node node3("j");
  Node node4("i");

  node1.next = &node2;
  node2.next = &node3;
  node3.next = &node4;

  head = removeNode(&node1, "i");
  assert(head->next->val == "j");  // -> h -> j -> i

  std::cout << "All tests passed!\n";
  return 0;
}
