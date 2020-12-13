#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void Inorder(Node* root) {
    if (not root) return;
    Inorder(root->left);
    cout << root->value << ' ';
    Inorder(root->right);
}

Node* Make(vi inorder, vi preorder, int& rootIdx, int i, int j) {
    if (i > j or rootIdx >= inorder.size()) return nullptr;
    int rootValue = preorder[rootIdx++];

    int inorderIdx = i;
    for (; inorderIdx <= j and inorder[inorderIdx] != rootValue; ++inorderIdx) {}

    Node* root = new Node(rootValue);
    root->left = Make(inorder, preorder, rootIdx, i, inorderIdx - 1);
    root->right = Make(inorder, preorder, rootIdx, inorderIdx + 1, j);
    return root;
}

void BuildFromInorderAndPreorder(vi inorder, vi preorder) {
    int rootIdx = 0;
    Node* root = Make(inorder, preorder, rootIdx, 0, inorder.size() - 1);
    Inorder(root);
}

int main() { TimeMeasure _; __x();
    vi inorder = { 9, 8, 4, 2, 10, 5, 10, 1, 6, 3, 13, 12, 7 };
    vi preorder = { 1, 2, 4, 8, 9, 5, 10, 10, 3, 6, 7, 12, 13 };
    BuildFromInorderAndPreorder(inorder, preorder); // 9 8 4 2 10 5 10 1 6 3 13 12 7
}
