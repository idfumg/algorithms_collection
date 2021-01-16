#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value) {}
};

void levelorder(Node* root) {
    if (not root) return;
    queue<Node*> q;
    q.push(root);
    while (not q.empty()) {
        Node* at = q.front(); q.pop();
        cout << at->value << ' ';
        if (at->left) q.push(at->left);
        if (at->right) q.push(at->right);
    }
}

int main() { TimeMeasure _; __x();
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    levelorder(root); // 1 2 3 4 5
}
