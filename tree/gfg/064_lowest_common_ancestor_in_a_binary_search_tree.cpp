#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void preorder(Node* root, vi& arr, int key) {
    if (not root) return;
    if (arr.empty() or arr.back() != key) arr.push_back(root->value);
    if (key < root->value) preorder(root->left, arr, key);
    if (key > root->value) preorder(root->right, arr, key);
    if (arr.back() != key) arr.pop_back();
}

int lca(Node* root, int from, int to) {
    vi arr1;
    preorder(root, arr1, from);

    vi arr2;
    preorder(root, arr2, to);

    if (arr1.size() > arr2.size()) swap(arr1, arr2);
    if (arr1.empty() or arr2.empty()) return -1;

    int n = arr1.size();
    for (int i = 0; i < n; ++i) {
        if (arr1[i] != arr2[i]) {
            return arr1[i - 1];
        }
    }
    return arr1.back();
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    cout << lca(root, 10, 14) << endl; // 12
    cout << lca(root, 8, 14) << endl; // 8
    cout << lca(root, 10, 22) << endl; // 20
}
