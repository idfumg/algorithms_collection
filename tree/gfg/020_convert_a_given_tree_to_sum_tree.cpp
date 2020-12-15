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

void convert(Node* root, Node* parent = nullptr) {
    if (not root) return;

    if (parent) parent->value += root->value;
    root->value = 0;

    convert(root->left, root);
    convert(root->right, root);

    if (root->left) root->value += root->left->value;
    if (root->right) root->value += root->right->value;
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
