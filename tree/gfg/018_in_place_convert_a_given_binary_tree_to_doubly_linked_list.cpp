#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void print(Node* head) {
    for (; head; head = head->right) cout << head->value << ' ';
}

void convert(Node* root, Node*& head, Node*& curr) {
    if (not root) return;
    convert(root->left, head, curr);
    if (not head) {
        head = new Node(root->value);
        curr = head;
    }
    else {
        curr->right = new  Node(root->value);
        curr = curr->right;
    }
    convert(root->right, head, curr);
}

Node* convert(Node* root) {
    Node* head = nullptr;
    Node* curr = nullptr;
    convert(root, head, curr);
    return head;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node* head = convert(root);
    print(head); // 25 12 30 10 36 15
}
