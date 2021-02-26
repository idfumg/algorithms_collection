#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

int MinDepth(Node* root) {
    if (not root) return 0;
    return 1 + min(MinDepth(root->left), MinDepth(root->right));
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << MinDepth(root) << endl;
}
