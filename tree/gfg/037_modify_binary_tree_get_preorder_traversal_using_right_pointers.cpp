#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void preorder(Node* root) {
    if (not root) return;
    cout << root->value << ' ';
    preorder(root->left);
    preorder(root->right);
}

Node* modify(Node* root) {
    if (not root) return nullptr;

    Node* left = modify(root->left);
    Node* right = modify(root->right);

    root->right = left;
    root->left = nullptr;

    Node* curr = left;
    while (curr and curr->right) curr = curr->right;
    if (curr) curr->right = right;

    return root;
}

int main() { TimeMeasure _; __x();
    /* Constructed binary tree is
            10
          /   \
        8      2
      /  \
    3     5
  */
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);

    modify(root);
    preorder(root); // 10 8 3 5 2
}
