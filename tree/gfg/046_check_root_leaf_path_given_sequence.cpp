#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

bool preorder(Node* root, vi& arr, vi& path) {
    if (not root) return false;
    path.push_back(root->value);
    if (path == arr) return true;
    if (preorder(root->left, arr, path) or preorder(root->right, arr, path)) return true;
    path.pop_back();
    return false;
}

bool IsPathExists(Node* root, vi arr) {
    vi path;
    return preorder(root, arr, path);
}

bool preorder(Node* root, vi& arr, int idx) {
    if (idx == arr.size() and not root) return true;
    if (not root) return false;
    if (root->value != arr[idx]) return false;
    return preorder(root->left, arr, idx + 1) or preorder(root->right, arr, idx + 1);
}

bool IsPathExists2(Node* root, vi arr) {
    int idx = 0;
    return preorder(root, arr, idx);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->left->left->left = new Node(1);
    root->right->left = new Node(6);
    root->right->left->right = new Node(7);

    cout << IsPathExists(root, {5, 8, 6, 7}) << endl; // 1
    cout << IsPathExists2(root, {5, 8, 6, 7}) << endl; // 1
}
