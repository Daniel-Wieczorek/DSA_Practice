// Get Node Value (https://www.structy.net/)
//
// Write a function, getNodeValue, that takes in a pointer to the head of a
// linked list and an index. The function should return the value of the linked
// list at the specified index.
//
// If there is no node at the given index, then return the empty string.

// Complexity:
// Time: O(n), where n is the number of nodes in the list, because we need to
// traverse the list to reach the specified index. Space: O(1), as we only use a
// few extra variables for the traversal.

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

std::string getNodeValue(Node* head, int idx) {
  Node* current = head;
  int i = 0;

  while (current != nullptr) {
    if (i == idx) {
      return current->val;
    }
    ++i;
    current = current->next;
  }

  return "";
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
  assert(getNodeValue(&a, 2) == "c");  // -> "c"
  assert(getNodeValue(&a, 3) == "d");  // -> "d"
  assert(getNodeValue(&a, 7) == "");   // -> ""

  Node node1("banana");
  Node node2("mango");

  node1.next = &node2;

  // banana -> mango
  assert(getNodeValue(&node1, 0) == "banana");  // -> "banana"

  std::cout << "All tests passed!\n";
  return 0;
}
