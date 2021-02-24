#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void preorder(Node* root, vi& path, vi& maxpath) {
    if (not root) return;
    path.push_back(root->value);
    if (path.size() > maxpath.size()) maxpath = path;
    preorder(root->left, path, maxpath);
    preorder(root->right, path, maxpath);
    path.pop_back();
}

void diameter(Node* root, vi& path, vi& maxpath) {
    if (not root) return;

    vi left;
    vi right;
    preorder(root->left, path, left);
    preorder(root->right, path, right);

    if (maxpath.size() < left.size() + right.size() + 1) {
        maxpath.assign(left.rbegin(), left.rend());
        maxpath.push_back(root->value);
        copy(right.begin(), right.end(), inserter(maxpath, maxpath.end()));
    }

    diameter(root->left, path, maxpath);
    diameter(root->right, path, maxpath);
}

void diameter(Node* root) {
    vi path;
    vi maxpath;
    diameter(root, path, maxpath);
    cout << maxpath << endl;
}

int main() { TimeMeasure _; __x();
    //           1
    //         /   \
    //        2     3
    //      /   \
    //     4     5
    //      \   / \
    //       8 6   7
    //      /
    //     9
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);
    root->left->left->right = new Node(8);
    root->left->left->right->left = new Node(9);

    diameter(root); // 9 8 4 2 1 3
}
