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

void inorder(Node* root, vi& arr) {
    if (not root) return;
    inorder(root->left, arr);
    arr.push_back(root->value);
    inorder(root->right, arr);
}

void inorder(Node* root, vi& arr, int& idx, Node*& a, Node*& b) {
    if (not root) return;
    inorder(root->left, arr, idx, a, b);
    if (root->value != arr[idx]) {
        if (not a) a = root;
        else if (not b) b = root;
    }
    ++idx;
    inorder(root->right, arr, idx, a, b);
}

void correct_bst(Node* root) {
    vi in;
    inorder(root, in);
    sort(in.begin(), in.end());

    int idx = 0;
    Node* a = nullptr;
    Node* b = nullptr;
    inorder(root, in, idx, a, b);
    swap(a->value, b->value);
}

int main() { TimeMeasure _; __x();
    /*   6
        /  \
       10    2
      / \   / \
     1   3 7  12
     10 and 2 are swapped
    */

    {
        Node* root = new Node(6);
        root->left = new Node(10);
        root->right = new Node(2);
        root->left->left = new Node(1);
        root->left->right = new Node(3);
        root->right->right = new Node(12);
        root->right->left = new Node(7);

        inorder(root); cout << endl; // 1 10 3 6 7 2 12
        correct_bst(root);
        inorder(root); cout << endl; // 1 2 3 6 7 10 12

        swap(root->left->value, root->left->left->value);
        inorder(root); cout << endl; // 2 1 3 6 7 10 12
        correct_bst(root);
        inorder(root); // 1 2 3 6 7 10 12
    }
}
