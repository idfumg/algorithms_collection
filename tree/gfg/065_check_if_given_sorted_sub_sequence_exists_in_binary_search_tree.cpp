#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value > root->value) root->right = insert(root->right, value);
    if (value < root->value) root->left = insert(root->left, value);
    return root;
}

void inorder(Node* root, vi& seq, int& idx) {
    if (not root) return;
    inorder(root->left, seq, idx);
    if (idx < seq.size() and seq[idx] == root->value) ++idx;
    inorder(root->right, seq, idx);
}

bool SequenceExist(Node* root, vi seq) {
    int idx = 0;
    inorder(root, seq, idx);
    return idx == seq.size();
}

int main() { TimeMeasure _; __x();
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 10);
    root = insert(root, 3);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 7);
    root = insert(root, 14);
    root = insert(root, 13);

    cout << SequenceExist(root, {4, 6, 8, 14}) << endl; // 1
    cout << SequenceExist(root, {4, 6, 8, 12, 13}) << endl; // 0
}
