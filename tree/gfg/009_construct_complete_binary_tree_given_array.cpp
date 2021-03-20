#include "../../template.hpp"

struct Node {
    int value = INF;
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

Node* ConstructCompleteBinaryTree(vi level) {
    int idx = 0;
    Node* root = new Node(level[idx++]);
    deque<Node*> pq;
    pq.push_back(root);
    while (not pq.empty()) {
        int n = pq.size();
        for (int i = 0; i < n; ++i) {
            Node* at = pq.front(); pq.pop_front();
            if (idx < level.size()) {
                at->left = new Node(level[idx++]);
                pq.push_back(at->left);
            }
            if (idx < level.size()) {
                at->right = new Node(level[idx++]);
                pq.push_back(at->right);
            }
        }
    }
    return root;
}

int main() { TimeMeasure _; __x();
    Node* root = ConstructCompleteBinaryTree({1, 2, 3, 4, 5, 6, 6, 6, 6});
    inorder(root); // 6 4 6 2 5 1 6 3 6
}
