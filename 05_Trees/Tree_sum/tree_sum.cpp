// Tree Sum (https://www.structy.net/)
//
// Write a function, treeSum, that takes in a pointer to the root of a binary
// tree that contains number values. The function should return the total sum
// of all values in the tree.

// Complexity:
// Time: O(n) where n is the number of nodes in the tree.
// Space: O(n) in the worst case due to storing nodes in the stack.

#include <cassert>
#include <iostream>
#include <stack>

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  explicit Node(const int initialVal)
      : val(initialVal), left(nullptr), right(nullptr) {}
};

int treeSum(Node* root) {
  if (root == nullptr) return 0;

  int sum = 0;
  std::stack<Node*> stack;
  stack.push(root);

  while (!stack.empty()) {
    Node* current = stack.top();
    stack.pop();
    sum += current->val;

    if (current->right != nullptr) stack.push(current->right);
    if (current->left != nullptr) stack.push(current->left);
  }

  return sum;
}

int main() {
  // Test case 1
  Node a(3);
  Node b(11);
  Node c(4);
  Node d(4);
  Node e(-2);
  Node f(1);

  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.right = &f;

  //       3
  //    /    \
  //   11     4
  //  / \      \
  // 4   -2     1

  assert(treeSum(&a) == 21);

  // Test case 2
  Node a2(1);
  Node b2(6);
  Node c2(0);
  Node d2(3);
  Node e2(-6);
  Node f2(2);
  Node g2(2);
  Node h2(2);

  a2.left = &b2;
  a2.right = &c2;
  b2.left = &d2;
  b2.right = &e2;
  c2.right = &f2;
  e2.left = &g2;
  f2.right = &h2;

  //      1
  //    /   \
  //   6     0
  //  / \     \
  // 3   -6    2
  //    /       \
  //   2         2

  assert(treeSum(&a2) == 10);

  std::cout << "All tests passed!\n";
  return 0;
}
