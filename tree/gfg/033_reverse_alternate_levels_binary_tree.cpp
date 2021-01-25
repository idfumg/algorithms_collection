#include "../../template.hpp"

struct Node {
    char value;
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

void ReverseAlternate(Node* root) {
    if (not root) return;
    deque<Node*> q;
    q.push_back(root);
    bool isReversed = false;
    while (not q.empty()) {
        int n = q.size();
        if (isReversed) {
            for (int i = 0, j = n - 1; i < j; ++i, --j) {
                swap(q[i]->value, q[j]->value);
            }
        }
        for (int i = 0; i < n; ++i) {
            Node* at = q.front(); q.pop_front();
            if (at->left) q.push_back(at->left);
            if (at->right) q.push_back(at->right);
        }
        isReversed = !isReversed;
    }
}

int main() { TimeMeasure _; __x();
    Node *root = new Node('a');
    root->left = new Node('b');
    root->right = new Node('c');
    root->left->left = new Node('d');
    root->left->right = new Node('e');
    root->right->left = new Node('f');
    root->right->right = new Node('g');
    root->left->left->left = new Node('h');
    root->left->left->right = new Node('i');
    root->left->right->left = new Node('j');
    root->left->right->right = new Node('k');
    root->right->left->left = new Node('l');
    root->right->left->right = new Node('m');
    root->right->right->left = new Node('n');
    root->right->right->right = new Node('o');

    inorder(root); cout << endl; // h d i b j e k a l f m c n g o
    ReverseAlternate(root);
    inorder(root); // o d n c m e l a k f j b i g h
}
