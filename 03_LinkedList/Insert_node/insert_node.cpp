// Insert Node (https://www.structy.net/)
//
// Write a function, insertNode, that takes in a pointer to the head of a linked
// list, a value, and an index. The function should insert a new node with the
// value into the list at the specified index. Consider the head of the linked
// list as index 0. The function should return the head of the resulting linked
// list.
//
// Do this in-place and be sure to dynamically allocate the new node in memory
// using new.
//
// You may assume that the input list is non-empty and the index is not greater
// than the length of the input list.
//
// Complexity:
// Time: O(n) where n is the size of the linked list.
// Space: O(1) as we are only using a constant amount of extra space for
// pointers.

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

Node* insertNode(Node* head, std::string value, int idx) {
  if (idx == 0) {
    Node* new_node = new Node(value);
    new_node->next = head;
    head = new_node;
    return head;
  }

  Node* current = head;
  int pos{0};
  while (current != nullptr) {
    if (pos == (idx - 1)) {
      Node* new_node = new Node(value);
      new_node->next = current->next;
      current->next = new_node;
      break;
    }
    ++pos;
    current = current->next;
  }
  return head;
}

void checkList(Node* head, const std::initializer_list<std::string>& expected) {
  Node* current = head;
  auto it = expected.begin();
  while (current != nullptr && it != expected.end()) {
    assert(current->val == *it);
    current = current->next;
    ++it;
  }
  assert(current == nullptr &&
         it == expected.end());  // Ensure we have matched all expected values
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
  Node* head = insertNode(&a, "x", 2);
  checkList(head, {"a", "b", "x", "c",
                   "d"});  // Assert the new list is a -> b -> x -> c -> d

  Node e("a");
  Node f("b");
  Node g("c");
  Node h("d");

  e.next = &f;
  f.next = &g;
  g.next = &h;

  // a -> b -> c -> d
  head = insertNode(&e, "v", 3);
  checkList(head, {"a", "b", "c", "v",
                   "d"});  // Assert the new list is a -> b -> c -> v -> d

  Node i("a");
  Node j("b");
  Node k("c");
  Node l("d");

  i.next = &j;
  j.next = &k;
  k.next = &l;

  // a -> b -> c -> d
  head = insertNode(&i, "m", 4);
  checkList(head, {"a", "b", "c", "d",
                   "m"});  // Assert the new list is a -> b -> c -> d -> m

  std::cout << "All tests passed!\n";
  return 0;
}
