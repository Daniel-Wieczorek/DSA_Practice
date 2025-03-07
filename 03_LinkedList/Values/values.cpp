// Linked List Values (https://www.structy.net/)
//
// Write a function, linkedListValues, that takes in a pointer to the head of a
// linked list as an argument. The function should return an array containing
// all values of the nodes in the linked list.
//
// Complexity:
// Time: O(n) where n is the number of nodes in the linked list.
// Space: O(n) where n is the number of nodes in the linked list.

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

class Node {
 public:
  std::string val;
  Node* next;

  explicit Node(const std::string& initialVal)
      : val{initialVal}, next{nullptr} {}
};

std::vector<std::string> linkedListValues(Node* head) {
  std::vector<std::string> result{};
  Node* current = head;
  while (current != nullptr) {
    result.push_back(current->val);
    current = current->next;
  }

  return result;
}

int main() {
  // Test Case 1: a -> b -> c -> d
  Node a("a");
  Node b("b");
  Node c("c");
  Node d("d");

  a.next = &b;
  b.next = &c;
  c.next = &d;

  const auto vec1 = linkedListValues(&a);
  assert((vec1 == std::vector<std::string>{"a", "b", "c", "d"}));

  // Test Case 2: x -> y
  Node x("x");
  Node y("y");

  x.next = &y;

  const auto vec2 = linkedListValues(&x);
  assert((vec2 == std::vector<std::string>{"x", "y"}));

  // Test Case 3: q
  Node q("q");

  const auto vec3 = linkedListValues(&q);
  assert(vec3 == std::vector<std::string>{"q"});

  std::cout << "All tests passed!\n";
  return 0;
}
