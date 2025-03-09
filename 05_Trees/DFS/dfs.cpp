// Depth First Values (https://www.structy.net/)
//
// Write a function, depthFirstValues, that takes in a pointer to the root of a
// binary tree. The function should return a vector containing all values of the
// tree in depth-first order.

// Complexity:
// Time: O(n) -> Each node is visited only once.
// Space: O(n) -> In the worst case (skewed tree), the stack will store all
// nodes.

#include <cassert>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

class Node {
 public:
  std::string val;
  Node* left;
  Node* right;

  explicit Node(const std::string& initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

std::vector<std::string> depthFirstValues(Node* root) {
  if (root == nullptr) {
    return {};
  }

  std::vector<std::string> output;
  std::stack<Node*> stack;
  stack.push(root);

  while (!stack.empty()) {
    Node* current = stack.top();
    stack.pop();
    output.push_back(current->val);

    if (current->right) {
      stack.push(current->right);
    }
    if (current->left) {
      stack.push(current->left);
    }
  }

  return output;
}

int main() {
  Node a("a");
  Node b("b");
  Node c("c");
  Node d("d");
  Node e("e");
  Node f("f");

  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  c.right = &f;

  //      a
  //    /   \
  //   b     c
  //  / \     \
  // d   e     f

  assert((depthFirstValues(&a) ==
          std::vector<std::string>{"a", "b", "d", "e", "c", "f"}));

  Node g("g");
  e.left = &g;

  //      a
  //    /   \
  //   b     c
  //  / \     \
  // d   e     f
  //    /
  //   g

  assert((depthFirstValues(&a) ==
          std::vector<std::string>{"a", "b", "d", "e", "g", "c", "f"}));

  Node single("a");
  assert((depthFirstValues(&single) == std::vector<std::string>{"a"}));

  Node x("a");
  Node y("b");
  Node z("c");
  Node w("d");
  Node v("e");

  x.right = &y;
  y.left = &z;
  z.right = &w;
  w.right = &v;

  //      a
  //       \
  //        b
  //       /
  //      c
  //       \
  //        d
  //         \
  //          e

  assert((depthFirstValues(&x) ==
          std::vector<std::string>{"a", "b", "c", "d", "e"}));

  std::cout << "All tests passed!\n";
  return 0;
}
