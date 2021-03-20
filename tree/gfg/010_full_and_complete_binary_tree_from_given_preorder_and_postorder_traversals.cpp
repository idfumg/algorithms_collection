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

Node* construct(vi pre, vi post, int& idx, int i, int j) {
    if (i > j) return nullptr;
    int rootValue = pre[idx++];
    if (idx > j) return new Node(rootValue);
    int leftRootValue = pre[idx];
    int pivot = i;
    while (pivot < j and post[pivot] != leftRootValue) ++pivot;
    Node* root = new Node(rootValue);
    root->left = construct(pre, post, idx, i, pivot + 1);
    root->right = construct(pre, post, idx, pivot + 1, j - 1);
    return root;
}

Node* construct(vi pre, vi post) {
    int idx = 0;
    return construct(pre, post, idx, 0, pre.size() - 1);
}

int main() { TimeMeasure _; __x();
    Node* root = construct({1, 2, 4, 8, 9, 5, 3, 6, 7}, {8, 9, 4, 5, 2, 6, 7, 3, 1});
    inorder(root); // // 8 4 9 2 5 1 6 3 7
}
