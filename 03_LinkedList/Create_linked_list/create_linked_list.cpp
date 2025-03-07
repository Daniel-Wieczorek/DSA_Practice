// Create Linked List (https://www.structy.net/)
//
// Write a function, createLinkedList, that takes in a vector of values as an
// argument. The function should create a linked list containing each element
// of the vector as the values of the nodes. The function should return the head
// of the linked list.
//
// Be sure to dynamically allocate the new nodes in memory using new.
//
// Complexity:
// Time: O(n) where n is the number of elements in the vector.
//
// Space: O(n) where n is the number of nodes created, as each node requires
//       additional space in memory.

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

Node* createLinkedList(const std::vector<std::string>& values) {
  if (values.empty()) {
    return nullptr;
  }

  Node* head = new Node(values.at(0));
  Node* tail = head;

  for (std::size_t i = 1; i < values.size(); ++i) {
    tail->next = new Node(values.at(i));
    tail = tail->next;  // Fixed typo: use 'tail->next' instead of 'new_node'
  }

  return head;
}

void PrintNodes(const Node* const head) {
  const Node* current = head;
  while (current != nullptr) {
    std::cout << current->val << ((current->next) ? " -> " : "");
    current = current->next;
  }
  std::cout << "\n";
}

int main() {
  std::vector<std::string> values1{"h", "e", "y"};
  const Node* const head1 = createLinkedList(values1);
  PrintNodes(head1);  // Should print: h -> e -> y

  std::vector<std::string> values2{"1", "7", "1", "8"};
  const Node* const head2 = createLinkedList(values2);
  PrintNodes(head2);  // Should print: 1 -> 7 -> 1 -> 8

  std::vector<std::string> values3{"a"};
  const Node* const head3 = createLinkedList(values3);
  PrintNodes(head3);  // Should print: a

  // Additional tests with assertions:
  assert(head1 != nullptr);  // Ensures head1 is not null
  assert(head2 != nullptr);  // Ensures head2 is not null
  assert(head3 != nullptr);  // Ensures head3 is not null

  std::cout << "All tests passed!\n";
  return 0;
}
