#include "../../template.hpp"

struct Node {
    int value = INF;
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

Node* construct(vi in, vi post, int& idx, int i, int j) {
    if (i > j or idx < 0) return nullptr;
    int rootValue = post[idx--];
    int pivot = i;
    while (pivot <= j and in[pivot] != rootValue) ++pivot;
    Node* root = new Node(rootValue);
    root->right = construct(in, post, idx, pivot + 1, j);
    root->left = construct(in, post, idx, i, pivot - 1);
    return root;
}

void MakePreorder(vi in, vi post) {
    int idx = in.size() - 1;
    Node* root = construct(in, post, idx, 0, in.size() - 1);
    preorder(root); cout << endl;
}

int main() { TimeMeasure _; __x();
    vi inorder = { 4, 8, 2, 5, 1, 6, 3, 7 };
    vi postorder = { 8, 4, 5, 2, 6, 7, 3, 1 };
    MakePreorder(inorder, postorder); // 1 2 4 8 5 3 6 7
}
