#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void Preorder(Node* root) {
    if (not root) return;
    cout << root->value << ' ';
    Preorder(root->left);
    Preorder(root->right);
}

Node* Make(vi inorder, vi postorder, int& rootIdx, int i, int j) {
    if (i > j or rootIdx < 0) return nullptr;
    int rootValue = postorder[rootIdx--];

    int inorderIdx = i;
    for (; inorderIdx <= j and inorder[inorderIdx] != rootValue; ++inorderIdx) {}

    Node* root = new Node(rootValue);
    root->right = Make(inorder, postorder, rootIdx, inorderIdx + 1, j);
    root->left = Make(inorder, postorder, rootIdx, i, inorderIdx - 1);
    return root;
}

void MakePreorder(vi inorder, vi postorder) {
    int rootIdx = inorder.size() - 1;
    Node* root = Make(inorder, postorder, rootIdx, 0, inorder.size() - 1);
    Preorder(root);
}

int main() { TimeMeasure _; __x();
    vi inorder = { 4, 8, 2, 5, 1, 6, 3, 7 };
    vi postorder = { 8, 4, 5, 2, 6, 7, 3, 1 };
    MakePreorder(inorder, postorder); // 1 2 4 8 5 3 6 7
}
