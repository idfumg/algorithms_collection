#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void inorder(Node* root, int& ans, int& curr, int& prev) {
    if (not root) return;
    inorder(root->left, ans, curr, prev);
    if (prev != -INF) {
        if (root->value > prev) ++curr;
        else curr = 0;
    }
    ans = max(ans, curr);
    prev = root->value;
    inorder(root->right, ans, curr, prev);
}

int LargestBSTinBT(Node* root) {
    int ans = 1;
    int curr = 1;
    int prev = -INF;
    inorder(root, ans, curr, prev);
    return ans;
}

int main() { TimeMeasure _; __x();
    /* Let us construct the following Tree
        60
       /  \
      65  70
     /
    50 */

    Node* root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    cout << LargestBSTinBT(root) << endl; // 2
}
