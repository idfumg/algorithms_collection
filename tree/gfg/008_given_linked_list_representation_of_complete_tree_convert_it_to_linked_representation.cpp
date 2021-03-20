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

Node* MakeList(vi arr) {
    Node* head = nullptr;
    Node* current = nullptr;
    for (int v : arr) {
        if (not head) {
            current = head = new Node(v);
        }
        else {
            current->right = new Node(v);
            current = current->right;
        }
    }
    return head;
}

Node* ConstructCompleteBinaryTree(Node* head) {
    if (not head) return nullptr;
    Node* root = new Node(head->value);
    deque<Node*> q;
    q.push_back(root);
    head = head->right;
    while (not q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            Node* at = q.front(); q.pop_front();
            if (head) {
                at->left = new Node(head->value);
                head = head->right;
                q.push_back(at->left);
            }
            if (head) {
                at->right = new Node(head->value);
                head = head->right;
                q.push_back(at->right);
            }
        }
    }
    return root;
}

int main() { TimeMeasure _; __x();
    Node* head = MakeList({10, 12, 15, 25, 30, 36});
    Node* root = ConstructCompleteBinaryTree(head);
    inorder(root); // 25 12 30 10 36 15
}
