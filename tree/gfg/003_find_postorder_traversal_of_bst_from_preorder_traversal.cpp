#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void postorder(Node* root) {
    if (not root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << ' ';
}

Node* construct(vi pre, int i, int j) {
    if (i > j) return nullptr;
    int rootValue = pre[i];
    int pivot = i + 1;
    while (pivot <= j and pre[pivot] < rootValue) ++pivot;
    Node* root = new Node(rootValue);
    root->left = construct(pre, i + 1, pivot - 1);
    root->right = construct(pre, pivot, j);
    return root;
}

Node* construct(vi pre) {
    return construct(pre, 0, pre.size() - 1);
}

void PostorderFromPreOrder(vi pre) {
    Node* root = construct(pre);
    postorder(root); cout << endl;
}

int main() { TimeMeasure _; __x();
    PostorderFromPreOrder({40, 30, 35, 80, 100}); // 35 30 100 80 40
    PostorderFromPreOrder({40, 30, 32, 35, 80, 90, 100, 120}); // 35 32 30 120 100 90 80 40
}
