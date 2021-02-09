#include "../../template.hpp"

struct Node {
    int value = -100;
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

void inorder_left(Node* root, unordered_set<int>& uncovered) {
    if (not root) return;
    uncovered.insert(root->value);
    if (root->left) inorder_left(root->left, uncovered);
    else inorder_left(root->right, uncovered);
}

void inorder_right(Node* root, unordered_set<int>& uncovered) {
    if (not root) return;
    uncovered.insert(root->value);
    if (root->right) inorder_right(root->right, uncovered);
    else inorder_right(root->left, uncovered);
}

void inorder_middle(Node* root, unordered_set<int>& uncovered, unordered_set<int>& covered) {
    if (not root) return;
    if (not uncovered.count(root->value)) covered.insert(root->value);
    inorder_middle(root->left, uncovered, covered);
    inorder_middle(root->right, uncovered, covered);
}

bool IsSumSame(Node* root) {
    unordered_set<int> uncovered;
    inorder_left(root, uncovered);
    inorder_right(root, uncovered);
    int uncoveredSum = accumulate(uncovered.begin(), uncovered.end(), 0);

    unordered_set<int> covered;
    inorder_middle(root, uncovered, covered);
    int coveredSum = accumulate(covered.begin(), covered.end(), 0);

    return uncoveredSum == coveredSum;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(9);
    root->left = new Node(4);
    root->left->left = new Node(3);
    root->left->right = new Node(6);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(7);
    root->right = new Node(17);
    root->right->right = new Node(22);
    root->right->right->left = new Node(20);

    cout << IsSumSame(root) << endl; // 0
}
