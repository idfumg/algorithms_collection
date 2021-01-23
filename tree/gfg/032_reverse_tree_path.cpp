#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

void inorder(Node* root, vector<Node*>& in, int key) {
    if (not root) return;
    if (in.empty() or in.back()->value != key) in.push_back(root);
    inorder(root->left, in, key);
    inorder(root->right, in, key);
}

void reverseTreePath(Node* root, int key) {
    vector<Node*> in;
    inorder(root, in, key);

    int n = in.size();
    for (int i = 0; i < n / 2; ++i) {
        swap(in[i]->value, in[n - i - 1]->value);
    }
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(7);
    root->left = new Node(6);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(1);

/*
     7
   /   \
  6     5
 / \   / \
4   3 2   1
*/

    reverseTreePath(root, 4);
    inorder(root); // 7 6 3 4 2 5 1
}
