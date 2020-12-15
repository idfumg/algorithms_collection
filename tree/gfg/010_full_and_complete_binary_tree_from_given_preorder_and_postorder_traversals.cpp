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

Node* construct(vi pre, vi post, int& idx, int from, int to) {
    if (from > to or idx >= pre.size()) return nullptr;

    int currentTreeRoot = pre[idx++];
    Node* root = new Node(currentTreeRoot);

    if (idx < pre.size()) {
        int leftTreeRoot = pre[idx];
        int i = from;
        for (; i <= to and post[i] != leftTreeRoot; ++i){}
        if (i <= to) {
            root->left = construct(pre, post, idx, from, i);
            root->right = construct(pre, post, idx, i + 1, to - 1);
        }
    }

    return root;
}

void construct(vi pre, vi post) {
    int idx = 0;
    Node* root = construct(pre, post, idx, 0, pre.size() - 1);
    inorder(root);
}

int main() { TimeMeasure _; __x();
    vi pre = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    vi post = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    construct(pre, post); // 8 4 9 2 5 1 6 3 7
}
