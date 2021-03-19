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

Node* construct(vi in, vi pre, int& idx, int i, int j) {
    if (i > j) return nullptr;
    int rootValue = pre[idx++];
    int pivot = i;
    while (pivot <= j and in[pivot] != rootValue) ++pivot;
    Node* root = new Node(rootValue);
    root->left = construct(in, pre, idx, i, pivot - 1);
    root->right = construct(in, pre, idx, pivot + 1, j);
    return root;
}

void BuildFromInorderAndPreorder(vi in, vi pre) {
    int idx = 0;
    Node* root = construct(in, pre, idx, 0, in.size() - 1);
    inorder(root); cout << endl;
}

int main() { TimeMeasure _; __x();
    vi inorder = { 9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7 };
    vi preorder = { 1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13 };
    BuildFromInorderAndPreorder(inorder, preorder); // 9 8 4 2 10 5 10 1 6 3 13 12 7
}
