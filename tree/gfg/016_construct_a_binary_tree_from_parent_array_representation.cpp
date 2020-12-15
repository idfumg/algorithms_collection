#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

Node* construct(vi arr, int rootIdx) {
    int n = arr.size();
    Node* root = new Node(rootIdx);
    for (int i = 0; i < n; ++i) {
        if (arr[i] == rootIdx) {
            if (not root->left) root->left = construct(arr, i);
            else if (not root->right) root->right = construct(arr, i);
        }
    }
    return root;
}

void construct(vi arr) {
    auto it = find(arr.begin(), arr.end(), -1);
    int rootIdx = distance(arr.begin(), it);

    Node* root = construct(arr, rootIdx);
    inorder(root);
    cout << endl;
}

int main() { TimeMeasure _; __x();
    construct({1, 5, 5, 2, 2, -1, 3}); // 0 1 5 6 3 2 4
    construct({-1, 0, 0, 1, 1, 3, 5}); // 6 5 3 1 4 0 2
}
