#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void inorder(Node* root, Node* pivot, Node*& prev, int& ans) {
    if (not root) return;
    inorder(root->left, pivot, prev, ans);
    if (prev and prev == pivot) ans = root->value;
    prev = root;
    inorder(root->right, pivot, prev, ans);
}

void inorderSuccesor(Node* root, Node* pivot) {
    Node* prev = nullptr;
    int ans = -1;
    inorder(root, pivot, prev, ans);
    cout << ans << endl;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    inorderSuccesor(root, root->right); // 6
    inorderSuccesor(root, root->left->left); // 2
    inorderSuccesor(root, root->right->right); // -1
    inorderSuccesor(root, root->left->right); // 1
}
