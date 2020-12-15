#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

Node* construct(vi pre, vi preMirror, int& idx, int from, int to) {
    if (from > to) return nullptr;
    int currentRoot = pre[idx++];
    int leftTreeRoot = pre[idx];
    Node* root = new Node(currentRoot);
    int i = from;
    for (; i <= to and preMirror[i] != leftTreeRoot; ++i){}
    if (i <= to) {
        root->left = construct(pre, preMirror, idx, i, to);
        root->right = construct(pre, preMirror, idx, from + 1, i - 1);
    }
    return root;
}

void construct(vi pre, vi preMirror) {
    int idx = 0;
    Node* root = construct(pre, preMirror, idx, 0, pre.size() - 1);
    inorder(root);
}

int main() { TimeMeasure _; __x();
    vi pre = {1,2,4,5,3,6,7};
    vi preMirror = {1,3,7,6,2,5,4};
    construct(pre, preMirror);
}
