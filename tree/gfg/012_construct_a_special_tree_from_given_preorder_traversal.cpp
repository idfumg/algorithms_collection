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

Node* construct(vi pre, vi preln, int& idx, int n) {
    if (idx == n) return nullptr;
    if (preln[idx] == 'L') {
        Node* root = new Node(pre[idx++]);
        return root;
    }
    Node* root = new Node(pre[idx++]);
    root->left = construct(pre, preln, idx, n);
    root->right = construct(pre, preln, idx, n);
    return root;
}

void construct(vi pre, vi preln) {
    int idx = 0;
    Node* root = construct(pre, preln, idx, pre.size());
    inorder(root);
}

int main() { TimeMeasure _; __x();
    vi pre = {10, 30, 20, 5, 15};
    vi preln = {'N', 'N', 'L', 'L', 'L'};
    construct(pre, preln);
}
