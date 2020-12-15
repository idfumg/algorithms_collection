#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

void normalize(Node* root, int diff) {
    if (not root) return;
    root->value += diff;
    normalize(root->left, diff);
}

void convert(Node* root) {
    if (not root) return;

    convert(root->left);
    convert(root->right);

    int sum = 0;
    if (root->left) sum += root->left->value;
    if (root->right) sum += root->right->value;

    if (root->value <= sum) root->value = sum;
    else normalize(root->left, root->value - sum);
}

int main() { TimeMeasure _; __x();
    Node *root = new Node(50);
    root->left = new Node(7);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(1);
    root->right->right = new Node(30);

    inorder(root);  // 3 7 5 50 1 2 30
    cout << endl;

    convert(root);

    inorder(root); // 14 19 5 50 1 31 30
    cout << endl;
}
