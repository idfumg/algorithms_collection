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

bool convert(Node* root) {
    if (not root) return true;
    if (not root->left and not root->right) return root->value;
    bool left = convert(root->left);
    bool right = convert(root->right);
    return root->value = left & right;
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
