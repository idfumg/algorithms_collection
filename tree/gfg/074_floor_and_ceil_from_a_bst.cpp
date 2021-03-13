#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void inorder(Node* root, int key, int& low, int& high) {
    if (not root) return;
    if (root->value == key) {
        low = high = key;
        return;
    }
    if (root->value > key) {
        high = root->value;
        inorder(root->left, key, low, high);
    }
    else if (root->value < key) {
        low = root->value;
        inorder(root->right, key, low, high);
    }
}

void FloorAndCeilOfBST(Node* root, int key) {
    int low = -1, high = -1;
    inorder(root, key, low, high);
    cout << low << ' ' << high << endl;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    FloorAndCeilOfBST(root, 11); // 10 12
    FloorAndCeilOfBST(root, 1); // -1 2
    FloorAndCeilOfBST(root, 6); // 6 6
    FloorAndCeilOfBST(root, 15); // 14 -1
}
