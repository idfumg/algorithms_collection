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

void inorder_iter(Node* node) {
    vector<Node*> path;
    for (; node; node = node->left) {
        path.push_back(node);
    }
    while (not path.empty()) {
        Node* node = path.back(); path.pop_back();
        cout << node->value << ' ';
        for (node = node->right; node; node = node->left) {
            path.push_back(node);
        }
    }
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    inorder(root); //  4 2 5 1 3
    cout << endl;
    inorder_iter(root); //  4 2 5 1 3
}
