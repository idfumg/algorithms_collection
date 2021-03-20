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

int sum(Node* root) {
    if (not root) return 0;
    return sum(root->left) + sum(root->right) + root->value;
}

void update(Node* root) {
    if (not root) return;
    root->value += sum(root->left);
    update(root->left);
    update(root->right);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);
    update(root);
    inorder(root); // 4 6 5 12 3 6
}
