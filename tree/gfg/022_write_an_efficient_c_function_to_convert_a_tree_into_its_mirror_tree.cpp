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

void mirror(Node* root) {
    if (not root) return;
    mirror(root->left);
    mirror(root->right);
    swap(root->left, root->right);
}

int main() { TimeMeasure _; __x();
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    inorder(root); cout << endl; // 4 2 5 1 3
    mirror(root);
    inorder(root); // 3 1 5 2 4
}
