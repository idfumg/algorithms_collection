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

void inorder(Node* root, vi& in) {
    if (not root) return;
    inorder(root->left, in);
    in.push_back(root->value);
    inorder(root->right, in);
}

bool IsTripletPresent(Node* root) {
    vi arr;
    inorder(root, arr);

    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            auto it = lower_bound(arr.begin() + j + 1, arr.end(), -(arr[i] + arr[j]));
            if (it != arr.end()) {
                debug(arr[i]); debug(arr[j]); debugn(*it);
                return true;
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    Node* root = nullptr;
    root = insert(root, 6);
    root = insert(root, -13);
    root = insert(root, 14);
    root = insert(root, -8);
    root = insert(root, 15);
    root = insert(root, 13);
    root = insert(root, 7);
    cout << IsTripletPresent(root) << endl; // 1
}
