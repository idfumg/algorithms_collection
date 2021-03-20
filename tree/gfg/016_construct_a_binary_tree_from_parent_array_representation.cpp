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

// Node* construct(vi arr, int idx) {
//     int n = arr.size();
//     Node* root = new Node(idx);
//     for (int i = 0; i < n; ++i) {
//         if (arr[i] == idx) {
//             if (not root->left) root->left = construct(arr, i);
//             else if (not root->right) root->right = construct(arr, i);
//         }
//     }
//     return root;
// }

Node* construct(vi arr, int idx) {
    int n = arr.size();
    Node* root = new Node(idx);
    deque<Node*> pq;
    pq.push_back(root);
    while (not pq.empty()) {
        int count = pq.size();
        for (int i = 0; i < count; ++i) {
            Node* at = pq.front(); pq.pop_front();
            for (int j = 0; j < n; ++j) {
                if (arr[j] == at->value) {
                    if (not at->left) {
                        at->left = new Node(j);
                        pq.push_back(at->left);
                    }
                    else if (not at->right) {
                        at->right = new Node(j);
                        pq.push_back(at->right);
                    }
                }
            }
        }
    }
    return root;
}

Node* construct(vi arr) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (arr[i] == -1) {
            return construct(arr, i);
        }
    }
    return nullptr;
}

int main() { TimeMeasure _; __x();
    inorder(construct({1, 5, 5, 2, 2, -1, 3})); cout << endl; // 0 1 5 6 3 2 4
    inorder(construct({-1, 0, 0, 1, 1, 3, 5})); cout << endl; // 6 5 3 1 4 0 2
}
