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

void print_list(Node* head) {
    for (; head; head = head->right) cout << head->value << ' ';
}

void inorder(Node* root, Node*& head, Node*& curr) {
    if (not root) return;
    inorder(root->left, head, curr);
    if (not head) {
        curr = head = new Node(root->value);
    }
    else {
        curr->right = new Node(root->value);
        curr = curr->right;
    }
    inorder(root->right, head, curr);
}

Node* bst_to_dll(Node* root) {
    Node* head = nullptr;
    Node* curr = nullptr;
    inorder(root, head, curr);
    return head;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(10);
    root->left = new Node(12);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node* head = bst_to_dll(root);
    print_list(head); // 25 12 30 10 36 15
}
