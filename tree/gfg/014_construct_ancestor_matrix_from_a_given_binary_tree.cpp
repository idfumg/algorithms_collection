#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

int count(Node* root) {
    if (not root) return 0;
    return 1 + count(root->left) + count(root->right);
}

void traverse(Node* root, vvi& arr, vi& elems) {
    if (not root) return;

    elems.push_back(root->value);
    traverse(root->left, arr, elems);
    traverse(root->right, arr, elems);
    elems.pop_back();

    int n = elems.size();
    for (int i = 0; i < n; ++i) {
        arr[elems[i]][root->value] = 1;
    }
}

vvi construct(Node* root) {
    int n = count(root);
    vvi arr(n, vi(n));
    vi elems;
    traverse(root, arr, elems);
    return arr;
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(3);
    vvi arr = construct(root);
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
/*
0 0 0 0 0 0
1 0 0 0 1 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
1 1 1 1 1 0
*/
}
