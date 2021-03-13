#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (root->value > value) root->left = insert(root->left, value);
    if (root->value < value) root->right = insert(root->right, value);
    return root;
}

bool isDeadEnd(Node* root, int low = 1, int high = INF) {
    if (not root) return false;
    if (low == high) return true;
    return isDeadEnd(root->left, low, root->value - 1) or isDeadEnd(root->right, root->value + 1, high);
}

int main() { TimeMeasure _; __x();
    /*   8
       /   \
      5    11
     /  \
    2    7
     \
      3
       \
        4 */
    Node* root = nullptr;
    root = insert(root, 8);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 11);
    root = insert(root, 4);
    cout << isDeadEnd(root) << endl; // 1
}
