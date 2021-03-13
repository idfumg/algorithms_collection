#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value > root->value) root->right = insert(root->right, value);
    if (value < root->value) root->left = insert(root->left, value);
    return root;
}

void inorder(Node* root, int& ans, int& prev, int pivot) {
    if (not root) return;
    if (pivot < root->value) inorder(root->left, ans, prev, pivot);
    if (prev == pivot) ans = root->value;
    prev = root->value;
    if (pivot > root->value) inorder(root->right, ans, prev, pivot);
}

int InOrderSuccessor(Node* root, int pivot) {
    int ans = -INF;
    int prev = -INF;
    inorder(root, ans, prev, pivot);
    return ans;
}

int main() { TimeMeasure _; __x();
    Node* root = nullptr;

    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 22);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);

    cout << InOrderSuccessor(root, 14) << endl; // 20
}
