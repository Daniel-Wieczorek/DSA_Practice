// Tree Value Count (https://www.structy.net/)
//
// Write a function, treeValueCount, that takes in a pointer to the root of a
// binary tree and a target value. The function should return the number of
// times that the target occurs in the tree.
//
// Complexity:
// Time: O(n), where n is the number of nodes in the binary tree. Each node is
// visited once. Space: O(n), for the stack used to store nodes during the
// traversal. In the worst case, the stack will store all nodes (e.g., a skewed
// tree).

#include <cassert>
#include <iostream>
#include <stack>

class Node {
 public:
  int val;
  Node* left;
  Node* right;

  explicit Node(const int initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

// Function to count occurrences of targetVal in the binary tree
int treeValueCount(Node* root, int targetVal) {
  int cnt = 0;
  if (root == nullptr) {
    return cnt;
  }

  std::stack<Node*> stack;
  stack.push(root);

  while (!stack.empty()) {
    const auto current = stack.top();
    if (current->val == targetVal) {
      ++cnt;
    }
    stack.pop();

    if (current->left != nullptr) {
      stack.push(current->left);
    }

    if (current->right != nullptr) {
      stack.push(current->right);
    }
  }

  return cnt;
}

int main() {
  // Test case 1
  Node a(12);
  Node b(6);
  Node c(6);
  Node d(4);
  Node e(6);
  Node f(12);

  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.right = &f;

  assert(treeValueCount(&a, 6) == 3);  // Expected: 3

  // Test case 2
  assert(treeValueCount(&a, 12) == 2);  // Expected: 2

  // Test case 3
  Node g(7);
  Node h(5);
  Node i(1);
  Node j(1);
  Node k(8);
  Node l(7);
  Node m(1);
  Node n(1);

  g.left = &h;
  g.right = &i;
  h.left = &j;
  h.right = &k;
  i.right = &l;
  k.left = &m;
  l.right = &n;

  assert(treeValueCount(&g, 1) == 4);  // Expected: 4

  // Test case 4
  assert(treeValueCount(&g, 9) == 0);  // Expected: 0

  std::cout << "All tests passed!\n";
  return 0;
}
