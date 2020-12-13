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



int main() { TimeMeasure _; __x();

}
