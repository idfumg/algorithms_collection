#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

int height(Node* root, int& ans) {
    if (not root) return 0;
    int left = height(root->left, ans);
    int right = height(root->right, ans);
    ans = max(ans, left + right + 1);
    return max(left, right) + 1;
}

int diameter(Node* root) {
    int ans = -1;
    height(root, ans);
    return ans;
}

int main() { TimeMeasure _; __x();
    /*
      1
     / \
    2   3
   / \
  4   5
*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << diameter(root) << endl; // 4
}
