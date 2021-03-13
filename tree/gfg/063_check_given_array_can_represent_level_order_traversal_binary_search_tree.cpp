#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value > root->value) root->right = insert(root->right, value);
    if (value < root->value) root->left = insert(root->left, value);
    return root;
}

bool LevelOrderIsOfBST(vi arr) {
    Node* root = nullptr;
    for (int value : arr) {
        root = insert(root, value);
    }

    vi order;
    deque<Node*> q;
    q.push_back(root);
    while (not q.empty()) {
        int n = q.size();
        while (n-- > 0) {
            Node* at = q.front(); q.pop_front();
            order.push_back(at->value);
            if (at->left) q.push_back(at->left);
            if (at->right) q.push_back(at->right);
        }
    }
    return order == arr;
}

int main() { TimeMeasure _; __x();
    cout << LevelOrderIsOfBST({7, 4, 12, 3, 6, 8, 1, 5, 10}) << endl; // 1
    cout << LevelOrderIsOfBST({11, 6, 13, 5, 12, 10}) << endl; // 0
}
