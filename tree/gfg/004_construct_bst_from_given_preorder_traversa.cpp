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

Node* Construct(vi preorder, int i, int j) {
    if (i > j) return nullptr;

    Node* root = new Node(preorder[i]);

    int k = i + 1;
    while (k <= j and preorder[k] < preorder[i]) ++k;
    if (k > j) {
        root->left = Construct(preorder, i + 1, j);
        return root;
    }

    root->left = Construct(preorder, i + 1, k - 1);
    root->right = Construct(preorder, k, j);
    return root;
}

void ConstructFromPreorder(vi preorder) {
    Node* root = Construct(preorder, 0, preorder.size() - 1);
    Inorder(root);
    cout << endl;
}

int main() { TimeMeasure _; __x();
    ConstructFromPreorder({40, 30, 35, 80, 100}); // 30 35 40 80 100
    ConstructFromPreorder({40, 30, 32, 35, 80, 90, 100, 120}); // 30 32 35 40 80 90 100 120
}
