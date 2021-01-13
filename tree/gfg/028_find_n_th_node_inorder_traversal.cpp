#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value) {}
};

void inorder(Node* root, int& n, int& ans) {
    if (not root) return;
    inorder(root->left, n, ans);
    if (--n == 0) ans = root->value;
    inorder(root->right, n, ans);
}

void NthInorder(Node* root, int n) {
    int ans = -1;
    inorder(root, n, ans);
    cout << ans << endl;
}

int main() { TimeMeasure _; __x();
    {
        Node* root = new Node(10);
        root->left = new Node(20);
        root->right = new Node(30);
        root->left->left = new Node(40);
        root->left->right = new Node(50);

        NthInorder(root, 4); // 10
    }
    {
        Node* root = new Node(7);
        root->left = new Node(2);
        root->right = new Node(3);
        root->right->left = new Node(8);
        root->right->right = new Node(5);
        NthInorder(root, 3); // 8
    }
}
