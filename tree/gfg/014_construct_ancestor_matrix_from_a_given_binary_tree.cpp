#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

int inorder(vvi& arr, vi& ancestors, Node* root) {
    if (not root) return 0;
    int at = root->value;
    for (int i = 0; i < ancestors.size(); ++i) {
        arr[ancestors[i]][at] = 1;
    }
    ancestors.push_back(at);
    int l = inorder(arr, ancestors, root->left);
    int r = inorder(arr, ancestors, root->right);
    ancestors.pop_back();
    return l + r + 1;
}

void construct(Node* root) {
    vvi arr(100, vi(100));
    vi ancestors;
    int n = inorder(arr, ancestors, root);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << ' ';
        }
        cout << endl;
    }
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(5);
    root->left = new Node(1);
    root->right = new Node(2);
    root->left->left = new Node(0);
    root->left->right = new Node(4);
    root->right->left = new Node(3);
    construct(root);
/*
0 0 0 0 0 0
1 0 0 0 1 0
0 0 0 1 0 0
0 0 0 0 0 0
0 0 0 0 0 0
1 1 1 1 1 0
*/
}
