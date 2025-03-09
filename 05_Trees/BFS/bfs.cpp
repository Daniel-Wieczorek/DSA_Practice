// Breadth First Values (https://www.structy.net/)
//
// Write a function, breadthFirstValues, that takes in a pointer to the root of
// a binary tree. The function should return a vector containing all values of
// the tree in breadth-first order.

// Complexity:
// Time: O(n) - Each node is visited once, and operations like enqueue/dequeue
// run in constant time.
// Space: O(n) - At worst, all nodes are stored in the queue.

#include <cassert>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Node {
 public:
  std::string val;
  Node *left;
  Node *right;

  explicit Node(const std::string &initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

std::vector<std::string> breadthFirstValues(Node *root) {
  std::vector<std::string> output{};
  if (root == nullptr) {
    return output;
  }

  std::queue<Node *> queue{};
  queue.push(root);

  while (!queue.empty()) {
    const auto current = queue.front();
    queue.pop();
    output.push_back(current->val);

    if (current->left != nullptr) {
      queue.push(current->left);
    }

    if (current->right != nullptr) {
      queue.push(current->right);
    }
  }

  return output;
}

int main() {
  // Test case 1
  Node a1("a"), b1("b"), c1("c"), d1("d"), e1("e"), f1("f");
  a1.left = &b1;
  a1.right = &c1;
  b1.left = &d1;
  b1.right = &e1;
  c1.right = &f1;
  assert((breadthFirstValues(&a1) ==
          std::vector<std::string>{"a", "b", "c", "d", "e", "f"}));

  // Test case 2
  Node a2("a"), b2("b"), c2("c"), d2("d"), e2("e"), f2("f"), g2("g"), h2("h");
  a2.left = &b2;
  a2.right = &c2;
  b2.left = &d2;
  b2.right = &e2;
  c2.right = &f2;
  e2.left = &g2;
  f2.right = &h2;
  assert((breadthFirstValues(&a2) ==
          std::vector<std::string>{"a", "b", "c", "d", "e", "f", "g", "h"}));

  // Test case 3 - Single node
  Node single("a");
  assert((breadthFirstValues(&single) == std::vector<std::string>{"a"}));

  // Test case 4 - Unbalanced tree
  Node a3("a"), b3("b"), c3("c"), d3("d"), e3("e"), x3("x");
  a3.right = &b3;
  b3.left = &c3;
  c3.left = &x3;
  c3.right = &d3;
  d3.right = &e3;
  assert((breadthFirstValues(&a3) ==
          std::vector<std::string>{"a", "b", "c", "x", "d", "e"}));

  std::cout << "All tests passed!\n";
  return 0;
}
