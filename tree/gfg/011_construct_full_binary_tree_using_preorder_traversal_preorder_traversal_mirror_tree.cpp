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

Node* construct(vi pre, vi premirror, int& idx, int i, int j) {
    if (i > j) return nullptr;
    int n = pre.size();
    int rootValue = pre[idx++];
    if (idx == n) return new Node(rootValue);

    int leftRootValue = pre[idx];
    int pivot = i;
    while (pivot <= j and premirror[pivot] != leftRootValue) ++pivot;

    Node* root = new Node(rootValue);
    root->left = construct(pre, premirror, idx, pivot, j);
    root->right = construct(pre, premirror, idx, i + 1, pivot - 1);
    return root;
}

Node* construct(vi pre, vi premirror) {
    int idx = 0;
    return construct(pre, premirror, idx, 0, pre.size() - 1);
}

int main() { TimeMeasure _; __x();
    Node* root = construct({1,2,4,5,3,6,7}, {1,3,7,6,2,5,4});
    inorder(root); // 4 2 5 1 6 3 7
}
