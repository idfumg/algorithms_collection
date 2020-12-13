#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void InorderTraversal(Node* root) {
    if (not root) return;
    InorderTraversal(root->left);
    cout << root->value << ' ';
    InorderTraversal(root->right);
}

void InorderTraversalIter(Node* node) {
    stack<Node*> stack;
    for (; node; node = node->left) stack.push(node);
    while (not stack.empty()) {
        Node* node = stack.top(); stack.pop();
        cout << node->value << ' ';
        node = node->right;
        for (; node; node = node->left) stack.push(node);
    }
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    InorderTraversal(root); //  4 2 5 1 3
    cout << endl;
    InorderTraversalIter(root);
}
