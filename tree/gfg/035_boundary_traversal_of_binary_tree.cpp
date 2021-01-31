#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void traverse_left(Node* root) {
    if (not root) return;
    if (not root->left and not root->right) return;
    cout << root->value << ' ';
    traverse_left(root->left);
}

void traverse_right(Node* root) {
    if (not root) return;
    if (not root->left and not root->right) return;
    traverse_right(root->right);
    cout << root->value << ' ';
}

void traverse_leaves(Node* root) {
    if (not root) return;
    if (not root->left and not root->right) cout << root->value << ' ';
    traverse_leaves(root->left);
    traverse_leaves(root->right);
}

void PrintBoundary(Node* root) {
    traverse_left(root);
    traverse_leaves(root);
    traverse_right(root->right);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    PrintBoundary(root); // 20 8 4 10 14 25 22
}
