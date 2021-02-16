#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

bool mirrors(Node* a, Node* b) {
    if (not a and not b) return true;
    if (not a or not b) return false;
    return a->value == b->value and mirrors(a->left, b->right) and mirrors(a->right, b->left);
}

int main() { TimeMeasure _; __x();
    Node* a = new Node(1);
    Node* b = new Node(1);
    a->left = new Node(2);
    a->right = new Node(3);
    a->left->left  = new Node(4);
    a->left->right = new Node(5);
    b->left = new Node(3);
    b->right = new Node(2);
    b->right->left = new Node(5);
    b->right->right = new Node(4);

    cout << mirrors(a, b) << endl; // 1
}
