#include "../../template.hpp"

struct Node {
    int value;
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

void inorder(Node* root, vi& in) {
    if (not root) return;
    inorder(root->left, in);
    in.push_back(root->value);
    inorder(root->right, in);
}

void replace(Node* root, vi& in, int& idx) {
    if (not root) return;
    replace(root->left, in, idx);
    if (idx == 0) root->value = in[idx + 1];
    else root->value = in[idx - 1] + in[idx + 1];
    replace(root->right, in, ++idx);
}

void ReplaceNodeWithSum(Node* root) {
    vi in;
    inorder(root, in);

    int idx = 0;
    replace(root, in, idx);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    preorder(root); cout << endl;
    ReplaceNodeWithSum(root);
    preorder(root); // 11 9 2 3 13 4 3
}
