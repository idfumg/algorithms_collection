#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

int traverse(Node* root) {
    if (not root) return 0;
    int left = traverse(root->left);
    int right = traverse(root->right);
    return root->value + left + right;
}

void update(Node* root) {
    if (not root) return;
    update(root->left);
    update(root->right);
    root->value += traverse(root->left);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    update(root);
    inorder(root); // 4 6 5 16 3 6
}
