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

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value > root->value) root->right = insert(root->right, value);
    if (value < root->value) root->left = insert(root->left, value);
    return root;
}

Node* construct_bst1(vi levelorder) {
    Node* root = nullptr;
    for (int value : levelorder) {
        root = insert(root, value);
    }
    return root;
}

struct Item {
    Node* at;
    int from1;
    int to1;
    int from2;
    int to2;
};

Node* construct_bst2(vi arr) {
    deque<Item> q;
    int idx = 0;
    Node* root = new Node(arr[idx++]);
    q.push_back({root, -INF, root->value - 1, root->value + 1, INF});
    int n = arr.size();
    while (not q.empty()) {
        int m = q.size();
        while (m-- > 0) {
            auto [at, from1, to1, from2, to2] = q.front(); q.pop_front();
            if (idx < n and arr[idx] >= from1 and arr[idx] <= to1) {
                int value = arr[idx++];
                at->left = new Node(value);
                q.push_back({at->left, from1, value - 1, value + 1, to1});
            }
            if (idx < n and arr[idx] >= from2 and arr[idx] <= to2) {
                int value = arr[idx++];
                at->right = new Node(value);
                q.push_back({at->right, from2, value - 1, value + 1, to2});
            }
        }
    }
    return root;
}

int main() { TimeMeasure _; __x();
    {
        Node* root = construct_bst1({7, 4, 12, 3, 6, 8, 1, 5, 10});
        inorder(root); cout << endl; // 1 3 4 5 6 7 8 10 12
    }
    {
        Node* root = construct_bst2({7, 4, 12, 3, 6, 8, 1, 5, 10});
        inorder(root); cout << endl; // 1 3 4 5 6 7 8 10 12
    }
}
