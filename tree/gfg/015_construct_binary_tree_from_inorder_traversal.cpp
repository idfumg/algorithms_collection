#include "../../template.hpp"

struct Node {
    int value = INF;
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

Node* construct(vi arr, int i, int j) {
    if (i > j) return nullptr;
    int key = i + 1;
    while (key <= j and arr[key] >= arr[key - 1]) ++key;
    Node* root = new Node(arr[key - 1]);
    root->left = construct(arr, i, key - 2);
    root->right = construct(arr, key, j);
    return root;
}

Node* construct(vi arr) {
    return construct(arr, 0, arr.size() - 1);
}

int main() { TimeMeasure _; __x();
    inorder(construct({5, 10, 40, 30, 28})); cout << endl; // 5 10 40 30 28
    inorder(construct({1, 5, 10, 40, 30, 15, 28, 20})); cout << endl; // 1 5 10 40 30 15 28 20
}
