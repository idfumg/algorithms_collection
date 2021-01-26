#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

void traverse(Node* root, map<int, vi>& map, int diagonal) {
    if (not root) return;
    map[diagonal].push_back(root->value);
    traverse(root->left, map, diagonal + 1);
    traverse(root->right, map, diagonal);
}

void DiagonalPrint(Node* root) {
    if (not root) return;

    map<int, vi> map;
    traverse(root, map, 0);

    for (const auto& [key, nodes] : map) {
        cout << nodes << endl;
    }
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    DiagonalPrint(root);
/*
8 10 14
3 6 7 13
1 4
*/
}
