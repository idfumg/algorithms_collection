#include "../../template.hpp"

struct Node {
    char value = -1;
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

Node* construct(string s, int& idx) {
    int n = s.size();
    if (idx == n) return nullptr;
    Node* root = new Node(s[idx++]);
    if (idx < n and s[idx++] == '(') {
        root->left = construct(s, idx);
    }
    if (idx < n and s[idx++] == '(') {
        root->right = construct(s, idx);
    }
    return root;
}

Node* construct(string s) {
    int idx = 0;
    return construct(s, idx);
}

int main() { TimeMeasure _; __x();
    preorder(construct("1(2)(3)")); cout << endl; // 1 2 3
    preorder(construct("4(2(3)(1))(6(5))")); // 4 2 3 1 6 5
}
