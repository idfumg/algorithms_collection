#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void dfs(Node* root, int& deepest, int level) {
    if (not root) return;
    if (level & 1) deepest = max(deepest, level);
    dfs(root->left, deepest, level + 1);
    dfs(root->right, deepest, level + 1);
}

int DeepestOddLevelDepth(Node* root) {
    int deepest = 1;
    dfs(root, deepest, 1);
    return deepest;
}

int main() { TimeMeasure _; __x();
    /*
    10
  /     \
28       13
       /     \
     14       15
             /  \
            23   24
*/
    Node* root = new Node(10);
    root->left = new Node(28);
    root->right = new Node(13);
    root->right->left = new Node(14);
    root->right->right = new Node(15);
    root->right->right->left = new Node(23);
    root->right->right->right = new Node(24);

    cout << DeepestOddLevelDepth(root) << endl; // 3
}
