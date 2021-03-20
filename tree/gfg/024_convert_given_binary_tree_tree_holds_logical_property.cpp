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

bool convert(Node* root) {
    if (not root) return false;
    if (not root->left and not root->right) return root->value;
    return root->value = convert(root->left) & convert(root->right);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(0);
    root->left = new Node(1);
    root->right = new Node(0);
    root->left->left = new Node(0);
    root->left->right = new Node(1);
    root->right->left = new Node(1);
    root->right->right = new Node(1);

    inorder(root); cout << endl;
    convert(root);
    inorder(root); // 0 0 1 0 1 1 1
}
