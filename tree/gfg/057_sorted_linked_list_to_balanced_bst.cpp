#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void preorder(Node* root) {
    if (not root) return;
    cout << root->value << ' ';
    preorder(root->left);
    preorder(root->right);
}

void print_list(Node* head) {
    for (; head; head = head->right) cout << head->value << ' ';
}

Node* create_list(vi values) {
    Node* head = nullptr;
    Node* curr = nullptr;
    for (int value : values) {
        if (not head) {
            head = new Node(value);
            curr = head;
        }
        else {
            curr->right = new Node(value);
            curr = curr->right;
        }
    }
    return head;
}

Node* find_mid(Node* head, Node* tail = nullptr) {
    Node* curr = head->right;
    while (curr and curr->right and curr != tail) {
        curr = curr->right->right;
        head = head->right;
    }
    return head;
}

Node* create_bst(Node* head, Node* tail = nullptr) {
    if (head == tail) return nullptr;
    Node* mid = find_mid(head, tail);
    Node* root = new Node(mid->value);
    root->left = create_bst(head, mid);
    root->right = create_bst(mid->right, tail);
    return root;
}

int main() { TimeMeasure _; __x();
    Node* head = create_list({1, 2, 3, 4, 5, 6, 7});
    print_list(head); cout << endl; // 1 2 3 4 5 6 7

    Node* root = create_bst(head);
    preorder(root); // 4 2 1 3 6 5 7

    return 0;
}
