#include "../../template.hpp"

struct Node {
    int value = INF;
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

void inorder(Node* root, vi& in) {
    if (not root) return;
    inorder(root->left, in);
    in.push_back(root->value);
    inorder(root->right, in);
}

void inorder(Node* root, vi& in, int& idx) {
    if (not root) return;
    inorder(root->left, in, idx);
    root->value = in[idx++];
    inorder(root->right, in, idx);
}

void BinaryTreeToBST(Node* root) {
    vi in;
    inorder(root, in);
    sort(in.begin(), in.end());
    int idx = 0;
    inorder(root, in, idx);
}

int main() { TimeMeasure _; __x();
/* Constructing tree given in the above figure
    10
   /  \
  30   15
 /      \
20       5*/

    Node* root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(15);
    root->left->left = new Node(20);
    root->right->right = new Node(5);

    BinaryTreeToBST(root);
    inorder(root); // 5 10 15 20 30
}
