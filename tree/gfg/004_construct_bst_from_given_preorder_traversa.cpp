#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

Node* construct(vi pre, int i, int j) {
    if (i > j) return nullptr;
    int rootValue = pre[i];
    int key = i + 1;
    while (key <= j and pre[key] <= rootValue) ++key;
    Node* root = new Node(rootValue);
    root->left = construct(pre, i + 1, key - 1);
    root->right = construct(pre, key, j);
    return root;
}

Node* ConstructFromPreorder(vi pre) {
    return construct(pre, 0, pre.size() - 1);
}

int main() { TimeMeasure _; __x();
    {
        Node* root = ConstructFromPreorder({40, 30, 35, 80, 100});
        inorder(root); cout << endl; // 30 35 40 80 100
    }
    {
        Node* root = ConstructFromPreorder({40, 30, 32, 35, 80, 90, 100, 120});
        inorder(root); cout << endl; // 30 32 35 40 80 90 100 120
    }
}
