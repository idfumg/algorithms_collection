#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

int height(Node* root, bool& isBalanced) {
    if (not root) return 0;
    int left = height(root->left, isBalanced) + 1;
    int right = height(root->right, isBalanced) + 1;
    int h = max(left, right);
    if (abs(left - right) > 2) isBalanced = false;
    return h;
}

bool IsBalanced(Node* root) {
    bool isBalanced = true;
    height(root, isBalanced);
    return isBalanced;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(100);
    root->right->left = new Node(50);
    root->right->right = new Node(150);
    root->right->left->left = new Node(40);

    cout << IsBalanced(root) << endl; // 1
}
