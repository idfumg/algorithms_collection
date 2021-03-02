#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void traverse(Node* root, int& ans, int prevmax) {
    if (not root) return;
    ans = max(ans, prevmax - root->value);
    traverse(root->left, ans, max(prevmax, root->value));
    traverse(root->right, ans, max(prevmax, root->value));
}

int MaxDiff(Node* root) {
    int ans = 0;
    traverse(root, ans, -1);
    return ans;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);
    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    cout << MaxDiff(root) << endl; // 7
}
