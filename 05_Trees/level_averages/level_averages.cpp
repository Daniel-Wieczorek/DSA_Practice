// Level Averages
//
// Write a function, levelAverages, that takes in a pointer to the root of a
// binary tree that contains number values. The function should return a vector
// containing the average value of each level.

// Complexity:
// Time: O(n), where n is the number of nodes in the tree.
// Space: O(n), as we store each level's values separately.

#include <cassert>
#include <iostream>
#include <queue>
#include <vector>

class Node {
 public:
  float val;
  Node *left;
  Node *right;

  explicit Node(const float initialVal)
      : val{initialVal}, left{nullptr}, right{nullptr} {}
};

std::vector<float> levelAverages(Node *root) {
  if (!root) return {};

  std::vector<float> result;
  std::queue<Node *> queue;
  queue.push(root);

  while (!queue.empty()) {
    int levelSize = queue.size();
    float sum = 0;

    for (int i = 0; i < levelSize; i++) {
      Node *current = queue.front();
      queue.pop();
      sum += current->val;

      if (current->left) queue.push(current->left);
      if (current->right) queue.push(current->right);
    }
    result.push_back(sum / levelSize);
  }

  return result;
}

int main() {
  {
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

    std::vector<float> expected = {3, 7.5, 1};
    assert(levelAverages(&a) == expected);
  }

  {
    Node a(5);
    Node b(11);
    Node c(54);
    Node d(20);
    Node e(15);
    Node f(1);
    Node g(3);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    e.left = &f;
    e.right = &g;

    //        5
    //     /    \
    //    11    54
    //  /   \
    // 20   15
    //      / \
    //     1  3

    std::vector<float> expected = {5, 32.5, 17.5, 2};
    assert(levelAverages(&a) == expected);
  }

  {
    Node a(-1);
    Node b(-6);
    Node c(-5);
    Node d(-3);
    Node e(0);
    Node f(45);
    Node g(-1);
    Node h(-2);

    a.left = &b;
    a.right = &c;
    b.left = &d;
    b.right = &e;
    c.right = &f;
    e.left = &g;
    f.right = &h;

    //        -1
    //      /   \
    //    -6    -5
    //   /  \     \
    // -3   0     45
    //     /       \
    //    -1       -2

    std::vector<float> expected = {-1, -5.5, 14, -1.5};
    assert(levelAverages(&a) == expected);
  }

  {
    Node q(13);
    Node r(4);
    Node s(2);
    Node t(9);
    Node u(2);
    Node v(42);

    q.left = &r;
    q.right = &s;
    r.right = &t;
    t.left = &u;
    u.right = &v;

    //        13
    //      /   \
    //     4     2
    //      \
    //       9
    //      /
    //     2
    //    /
    //   42

    std::vector<float> expected = {13, 3, 9, 2, 42};
    assert(levelAverages(&q) == expected);
  }

  std::cout << "All tests passed!\n";
  return 0;
}
