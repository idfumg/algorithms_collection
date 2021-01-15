#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value) {}
};

void postorder(Node* root, int& n, int& ans) {
    if (not root) return;
    postorder(root->left, n, ans);
    postorder(root->right, n, ans);
    if(--n == 0) ans = root->value;
}

void NthPostordernode(Node* root, int n) {
    int ans = -1;
    postorder(root, n, ans);
    cout << ans << endl;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(25);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(18);
    root->left->right = new Node(22);
    root->right->left = new Node(24);
    root->right->right = new Node(32);

    NthPostordernode(root, 6); // 30
}
