#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void Preorder(Node* root) {
    if (not root) return;
    cout << root->value << ' ';
    Inorder(root->left);
    Inorder(root->right);
}

Node* construct(string s, int& idx) {
    if (idx == s.size()) return nullptr;
    Node* root = new Node(s[idx++] - '0');
    if (idx < s.size() and s[idx++] == '(') {
        root->left = construct(s, idx);
    }
    if (idx < s.size() and s[idx++] == '(') {
        root->right = construct(s, idx);
    }
    return root;
}

void construct(string s) {
    int idx = 0;
    Node* root = construct(s, idx);
    Preorder(root);
    cout << endl;
}

int main() { TimeMeasure _; __x();
    construct("1(2)(3)");
    construct("4(2(3)(1))(6(5))");
}
