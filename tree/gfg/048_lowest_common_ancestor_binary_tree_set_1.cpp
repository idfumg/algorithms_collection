#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void preorder(Node* root, int key, vi& arr) {
    if (not root) return;
    if (arr.empty() or arr.back() != key) arr.push_back(root->value);
    preorder(root->left, key, arr);
    preorder(root->right, key, arr);
    if (arr.back() != key) arr.pop_back();
}

int FindLCA(Node* root, int key1, int key2) {
    vi arr1, arr2;
    preorder(root, key1, arr1);
    preorder(root, key2, arr2);

    if (arr1.empty() or arr2.empty()) return -1;
    if (arr1.size() > arr2.size()) swap(arr1, arr2);
    int n = arr1.size();

    for (int i = 0; i < n; ++i) {
        if (arr1[i] != arr2[i]) {
            return arr1[i - 1];
        }
    }
    return arr1.back();
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    cout << FindLCA(root, 4, 5) << endl; // 2
    cout << FindLCA(root, 4, 6) << endl; // 1
    cout << FindLCA(root, 3, 4) << endl; // 1
    cout << FindLCA(root, 2, 4) << endl; // 2
    cout << FindLCA(root, 2, 40) << endl; // -1
}
