#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void Preorder(Node* root) {
    if (not root) return;
    cout << root->value << ' ';
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node* root, vi& in) {
    if (not root) return;
    Inorder(root->left, in);
    in.push_back(root->value);
    Inorder(root->right, in);
}

void Preorder(Node* root, vi& in, int& idx) {
    if (not root) return;
    root->value = in[idx++];
    Preorder(root->left, in, idx);
    Preorder(root->right, in, idx);
}

void ConvertToMinHeap(Node* root) {
    vi in;
    Inorder(root, in);

    int idx = 0;
    Preorder(root, in, idx);
}

int main() { TimeMeasure _; __x();
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    ConvertToMinHeap(root);
    Preorder(root); // 1 2 3 4 5 6 7
}
