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

void Density(Node* root, int& count, int& height, int currentHeight) {
    if (not root) return;
    ++count;
    height = max(height, currentHeight);
    Density(root->right, count, height, currentHeight + 1);
    Density(root->left, count, height, currentHeight + 1);
}

void Density(Node* root) {
    if (not root) return;
    int count = 0;
    int height = 1;
    Density(root, count, height, 1);
    cout << static_cast<double>(count) / height << endl;
}

int main() { TimeMeasure _; __x();
    {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        Density(root); // 1.5
    }
    {
        Node* root = new Node(1);
        root->left = new Node(2);
        root->left->left = new Node(3);
        Density(root); // 1
    }
}
