#include "../../template.hpp"

struct Node {
    char value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void preorder(Node* root) {
    if (not root) return;
    cout << root->value << ' ';
    preorder(root->left);
    preorder(root->right);
}

Node* construct(string s, int& idx) {
    if (idx >= s.size()) return nullptr;
    Node* root = new Node(s[idx++]);
    if (s[idx] == '?') {
        root->left = construct(s, ++idx);
        root->right = construct(s, ++idx);
    }
    return root;
}

Node* construct(string s) {
    int idx = 0;
    return construct(s, idx);
}

int main() { TimeMeasure _; __x();
    Node* root = construct("a?b?c:d: e");
    preorder(root); // a b c d e
}
