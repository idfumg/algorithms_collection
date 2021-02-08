#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value) {}
};

void preorder(Node* root) {
    if (not root) return;
    cout << root->value << ' ';
    preorder(root->left);
    preorder(root->right);
}

int IsSumTree(Node* root, bool& ans) {
    if (not root) return 0;
    int left = IsSumTree(root->left, ans);
    int right = IsSumTree(root->right, ans);
    if ((root->left or root->right) and root->value != left + right) ans = false;
    return left + right + root->value;
}

bool IsSumTree(Node* root) {
    bool ans = true;
    IsSumTree(root, ans);
    return ans;
}

int main() { TimeMeasure _; __x();
    Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    cout << IsSumTree(root) << endl; // 1
}
