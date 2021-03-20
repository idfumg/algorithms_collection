#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

void convert(Node* root, Node* parent) {
    if (not root) return;
    if (parent) parent->value += root->value;
    root->value = 0;
    convert(root->left, root);
    convert(root->right, root);
}

void convert(Node* root) {
    convert(root, nullptr);
}

int main() { TimeMeasure _; __x();
    Node *root = new Node(10);
    root->left = new Node(-2);
    root->right = new Node(6);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);

    convert(root);
    inorder(root); // 0 4 0 20 0 12 0
}
