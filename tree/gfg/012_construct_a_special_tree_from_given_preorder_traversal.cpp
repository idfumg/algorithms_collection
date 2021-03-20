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

Node* construct(vi pre, vi preln, int& idx) {
    int n = pre.size();
    if (idx == n) return nullptr;
    if (preln[idx] == 'L') return new Node(pre[idx++]);
    Node* root = new Node(pre[idx++]);
    root->left = construct(pre, preln, idx);
    root->right = construct(pre, preln, idx);
    return root;
}

Node* construct(vi pre, vi preln) {
    int idx = 0;
    return construct(pre, preln, idx);
}

int main() { TimeMeasure _; __x();
/*
          10
         /  \
        30   15
       /  \
      20   5
*/
    Node* root = construct({10, 30, 20, 5, 15}, {'N', 'N', 'L', 'L', 'L'});
    inorder(root); // 20 30 5 10 15
}
