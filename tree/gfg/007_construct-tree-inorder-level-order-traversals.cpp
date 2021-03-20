#include "../../template.hpp"

struct Node {
    int value = INF;
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

vi MakeLevelOrder(vi in, vi level, int key, int i, int j) {
    unordered_set<int> map;
    for (int k = i; k <= j; ++k) {
        map.insert(in[k]);
    }
    vi order;
    for (int v : level) {
        if (map.count(v)) {
            order.push_back(v);
        }
    }
    return order;
}

Node* construct(vi in, vi level, int i, int j) {
    if (i > j) return nullptr;
    int rootValue = level[0];
    int pivot = i;
    while (pivot <= j and in[pivot] != rootValue) ++pivot;
    Node* root = new Node(rootValue);
    root->left = construct(in, MakeLevelOrder(in, level, rootValue, i, pivot - 1), i, pivot - 1);
    root->right = construct(in, MakeLevelOrder(in, level, rootValue, pivot + 1, j), pivot + 1, j);
    return root;
}

Node* construct(vi in, vi level) {
    return construct(in, level, 0, in.size() - 1);
}

int main() { TimeMeasure _; __x();
    Node* root = construct({4, 8, 10, 12, 14, 20, 22}, {20, 8, 22, 4, 12, 10, 14});
    inorder(root); // 4 8 10 12 14 20 22
}
