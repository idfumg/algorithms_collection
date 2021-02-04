#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

bool IsSumProperty(Node* root) {
    if (not root) return true;
    if (not root->left and not root->right) return true;
    int sum = 0;
    if (root->left) sum += root->left->value;
    if (root->right) sum += root->right->value;
    return root->value == sum and IsSumProperty(root->left) and IsSumProperty(root->right);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->right = new Node(2);
    cout << IsSumProperty(root) << endl; // 1
}
