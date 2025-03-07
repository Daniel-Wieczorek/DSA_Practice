// Add Lists (https://www.structy.net/)
//
// Write a function, addLists, that takes in pointers to the heads of two linked
// lists, each representing a number. The nodes of the linked lists contain
// digits as values. The nodes in the input lists are reversed; this means that
// the least significant digit of the number is the head. The function should
// return the head of a new linked list representing the sum of the input lists.
// The output list should have its digits reversed as well.
//
// You must do this by traversing through the linked lists once.
//
// Complexity:
// Time: O(n) where n is the length of the longer list.
//
// Space: O(n) where n is the number of nodes in the resulting list.

#include <cassert>
#include <iostream>

class Node {
 public:
  int val;
  Node *next;

  explicit Node(int initialVal) : val{initialVal}, next{nullptr} {}

  // Destructor skipped on purpose, memory will be leaked!
};

Node *addLists(Node *head1, Node *head2) {
  Node *dummyHead = new Node(0);
  Node *current = dummyHead;
  int carry = 0;

  while (head1 != nullptr || head2 != nullptr || carry != 0) {
    int sum = carry;

    if (head1 != nullptr) {
      sum += head1->val;
      head1 = head1->next;
    }

    if (head2 != nullptr) {
      sum += head2->val;
      head2 = head2->next;
    }

    carry = sum / 10;
    current->next = new Node(sum % 10);
    current = current->next;
  }

  return dummyHead->next;
}

int main() {
  // Test case 1
  Node a1(1);
  Node a2(2);
  Node a3(6);
  a1.next = &a2;
  a2.next = &a3;
  // 1 -> 2 -> 6

  Node b1(4);
  Node b2(5);
  Node b3(3);
  b1.next = &b2;
  b2.next = &b3;
  // 4 -> 5 -> 3

  Node *result = addLists(&a1, &b1);
  assert(result->val == 5);
  assert(result->next->val == 7);
  assert(result->next->next->val == 9);
  // 5 -> 7 -> 9

  // Test case 2
  Node a4(1);
  Node a5(4);
  Node a6(5);
  Node a7(7);
  a4.next = &a5;
  a5.next = &a6;
  a6.next = &a7;
  // 1 -> 4 -> 5 -> 7

  Node b4(2);
  Node b5(3);
  b4.next = &b5;
  // 2 -> 3

  result = addLists(&a4, &b4);
  assert(result->val == 3);
  assert(result->next->val == 7);
  assert(result->next->next->val == 5);
  assert(result->next->next->next->val == 7);
  // 3 -> 7 -> 5 -> 7

  // Test case 3
  Node a8(9);
  Node a9(3);
  a8.next = &a9;
  // 9 -> 3

  Node b6(7);
  Node b7(4);
  b6.next = &b7;
  // 7 -> 4

  result = addLists(&a8, &b6);
  assert(result->val == 6);
  assert(result->next->val == 8);
  // 6 -> 8

  // Test case 4
  Node a10(9);
  Node a11(8);
  a10.next = &a11;
  // 9 -> 8

  Node b8(7);
  Node b9(4);
  b8.next = &b9;
  // 7 -> 4

  result = addLists(&a10, &b8);
  assert(result->val == 6);
  assert(result->next->val == 3);
  assert(result->next->next->val == 1);
  // 6 -> 3 -> 1

  std::cout << "All tests passed!\n";
  return 0;
}
