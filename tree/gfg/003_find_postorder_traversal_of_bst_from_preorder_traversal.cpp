#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

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

void Postorder(Node* root) {
    if (not root) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->value << ' ';
}

void PostorderFromPreOrder(vi preorder) {
    Node* root = Construct(preorder, 0, preorder.size() - 1);
    Postorder(root);
    cout << endl;
}

int main() { TimeMeasure _; __x();
    PostorderFromPreOrder({40, 30, 35, 80, 100}); // 35 30 100 80 40
    PostorderFromPreOrder({40, 30, 32, 35, 80, 90, 100, 120}); // 35 32 30 120 100 90 80 40
}
