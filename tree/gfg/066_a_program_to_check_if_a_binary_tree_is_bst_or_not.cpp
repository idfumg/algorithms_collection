#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

bool IsBST(Node* root, int low = -INF, int high = INF) {
    if (not root) return true;
    if (root->value < low or root->value > high) return false;
    return IsBST(root->left, low, root->value - 1) and IsBST(root->right, root->value + 1, high);
}

int main() { TimeMeasure _; __x();
    {
        Node* root = new Node(4);
        root->left = new Node(2);
        root->right = new Node(5);
        root->left->left = new Node(1);
        root->left->right = new Node(3);
        cout << IsBST(root) << endl; // 1
    }
    {
        Node* root = new Node(3);
        root->left = new Node(2);
        root->right = new Node(5);
        root->left->left = new Node(1);
        root->left->right = new Node(4);
        cout << IsBST(root) << endl; // 0
    }
}
