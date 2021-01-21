#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value) {}
};

void reverseLevelOrder(Node* root) {
    if (not root) return;
    deque<Node*> q;
    q.push_back(root);
    bool isInversed = true;
    while (not q.empty()) {
        if (isInversed) {
            for_each(q.rbegin(), q.rend(), [](Node* node){cout << node->value << ' ';});;
        }
        else {
            for_each(q.begin(), q.end(), [](Node* node){cout << node->value << ' ';});;
        }
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            Node* at = q.front(); q.pop_front();
            if (at->left) q.push_back(at->left);
            if (at->right) q.push_back(at->right);
        }
        isInversed = !isInversed;
    }
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);

    reverseLevelOrder(root); // 1 2 3 4 5 6 7
}
