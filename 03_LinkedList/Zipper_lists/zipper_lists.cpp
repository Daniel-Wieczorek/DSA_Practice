// Zipper Lists (https://www.structy.net/)
//
// Write a function, zipperLists, that takes in pointers to the heads of two
// linked lists. The function should zipper the two lists together into a
// single linked list by alternating nodes. If one of the linked lists is
// longer than the other, the resulting list should terminate with the remaining
// nodes. The function should return a pointer to the head of the zippered
// linked list.
//
// Do this in-place, by mutating the original Nodes.
//
// You may assume that both input lists are non-empty.
//
// Complexity:
// Time: O(n + m), where n is the length of the first linked list and m is the
// length of the second linked list. The time complexity comes from the need
// to traverse both lists fully.
// Space: O(1), as no extra space is used apart from the input linked lists.

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

// Function to print the linked list
void printList(Node* head) {
  Node* current = head;
  while (current != nullptr) {
    std::cout << current->val;
    if (current->next != nullptr) {
      std::cout << " -> ";
    }
    current = current->next;
  }
  std::cout << std::endl;
}

Node* zipperLists(Node* head1, Node* head2) {
  Node* current_h1 = head1;
  Node* current_h2 = head2;
  Node* tail_h1 = head1;
  Node* tail_h2 = head2;
  int count(0);

  while (current_h1 != nullptr) {
    if (count % 2 == 0) {
      tail_h1 = current_h1->next;
      current_h1->next = tail_h2;
      current_h1 = tail_h1;
    } else {
      tail_h2 = current_h2->next;
      current_h2->next = tail_h1;
      current_h2 = tail_h2;
    }

    ++count;
    if (current_h2 == nullptr) {
      break;
    }
  }
  return head1;
}

int main() {
  // Test 1
  Node s("s");
  Node t("t");
  s.next = &t;
  // s -> t

  Node one("1");
  Node two("2");
  Node three("3");
  Node four("4");
  one.next = &two;
  two.next = &three;
  three.next = &four;
  // 1 -> 2 -> 3 -> 4

  Node* result1 = zipperLists(&s, &one);
  printList(result1);
  assert(result1->val == "s");
  assert(result1->next->val == "1");
  assert(result1->next->next->val == "t");
  assert(result1->next->next->next->val == "2");
  assert(result1->next->next->next->next->val == "3");
  assert(result1->next->next->next->next->next->val == "4");

  // Test 2
  Node a("a");
  Node b("b");
  Node c("c");
  a.next = &b;
  b.next = &c;
  // a -> b -> c

  Node x("x");
  Node y("y");
  Node z("z");
  x.next = &y;
  y.next = &z;
  // x -> y -> z

  Node* result2 = zipperLists(&a, &x);
  printList(result2);
  assert(result2->val == "a");
  assert(result2->next->val == "x");
  assert(result2->next->next->val == "b");
  assert(result2->next->next->next->val == "y");
  assert(result2->next->next->next->next->val == "c");
  assert(result2->next->next->next->next->next->val == "z");

  // Test 3 - longer list 1
  Node p("p");
  Node q("q");
  Node r("r");
  p.next = &q;
  q.next = &r;
  // p -> q -> r

  Node x1("x1");
  Node y1("y1");
  x1.next = &y1;
  // x1 -> y1

  Node* result3 = zipperLists(&p, &x1);
  printList(result3);
  assert(result3->val == "p");
  assert(result3->next->val == "x1");
  assert(result3->next->next->val == "q");
  assert(result3->next->next->next->val == "y1");
  assert(result3->next->next->next->next->val == "r");

  // Test 4 - one-element lists
  Node w("w");
  const Node* const result4 = zipperLists(&w, nullptr);
  assert(result4->val == "w");

  std::cout << "All tests passed!\n";
  return 0;
}
