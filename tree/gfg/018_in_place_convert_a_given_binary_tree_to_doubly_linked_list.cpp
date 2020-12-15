#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void print(Node* head) {
    while (head) {
        cout << head->value << ' ';
        head = head->right;
    }
}

Node* convert_(Node* root) {
    if (not root) return nullptr;
    Node* head = new Node(root->value);
    if (root->left) {
        head->left = convert_(root->left);
        while (head->left->right) head->left = head->left->right;
        head->left->right = head;
    }
    if (root->right) {
        head->right = convert_(root->right);
        while (head->right->left) head->right = head->right->left;
        head->right->left = head;
    }
    return head;
}

Node* convert(Node* root) {
    if (not root) return nullptr;
    Node* head = convert_(root);
    while (head and head->left != nullptr) {
        head = head->left;
    }
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
