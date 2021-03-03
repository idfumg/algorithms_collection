#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

int height(Node* root) {
    if (not root) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

bool IsBalanced(Node* root) {
    if (not root) return true;
    int left = height(root->left);
    int right = height(root->right);
    return abs(left - right) <= 1 and IsBalanced(root->left) and IsBalanced(root->right);
}

int main() { TimeMeasure _; __x();
    /* Constructed binary tree is
       1
     /   \
    2     3
   / \   /
  4   5 6
 /
7
*/
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->left = new Node(7);

    cout << IsBalanced(root) << endl; // 1
}
