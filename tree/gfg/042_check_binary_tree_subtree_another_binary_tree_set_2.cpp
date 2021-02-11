#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

bool preorder(Node* T, Node* S) {
    if (not T and not S) return true;
    if (not T or not S) return false;
    return T->value == S->value and preorder(T->left, S->left) and preorder(T->right, S->right);
}

bool IsSubtree(Node* T, Node* S) {
    if (not S) return false;
    return preorder(T, S) or IsSubtree(T, S->left) or IsSubtree(T, S->right);
}

int main() { TimeMeasure _; __x();
    {
        Node* T = new Node('a');
        T->left = new Node('b');
        T->right = new Node('d');
        T->left->left = new Node('c');
        T->right->right = new Node('e');

        Node* S = new Node('a');
        S->left = new Node('b');
        S->left->left = new Node('c');
        S->right = new Node('d');

        cout << IsSubtree(T, S) << endl; // 0
    }
    {
        Node* T = new Node('x');
        T->left = new Node('a');
        T->left->right = new Node('c');
        T->right = new Node('b');

        Node* S = new Node('z');
        S->left = new Node('x');
        S->left->left = new Node('a');
        S->left->left->right = new Node('c');
        S->left->right = new Node('b');
        S->right = new Node('e');
        S->right->right = new Node('k');

        cout << IsSubtree(T, S) << endl; // 1
    }
}
