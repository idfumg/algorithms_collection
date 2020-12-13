#include "../../template.hpp"

struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) : value(value), left(nullptr), right(nullptr) {}
};

void Inorder(TreeNode* root) {
    if (not root) return;
    Inorder(root->left);
    cout << root->value << ' ';
    Inorder(root->right);
}

TreeNode* Make(vi arr) {
    queue<TreeNode*> q;
    int n = arr.size();
    int i = 0;

    TreeNode* root = new TreeNode(arr[i]);
    q.push(root);
    ++i;

    while (not q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (i < n) {
            node->left = new TreeNode(arr[i++]);
            q.push(node->left);
        }
        if (i < n) {
            node->right = new TreeNode(arr[i++]);
            q.push(node->right);
        }
    }

    return root;
}

void ConstructCompleteBinaryTree(vi arr) {
    Inorder(Make(arr));
}

int main() { TimeMeasure _; __x();
    vi arr = { 1, 2, 3, 4, 5, 6, 6, 6, 6 };
    ConstructCompleteBinaryTree(arr); // 6 4 6 2 5 1 6 3 6
}
