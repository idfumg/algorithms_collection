#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

Node* construct(vi in, int from, int to) {
    if (from > to) return nullptr;
    int maxi = in[0];
    int rootIdx = 0;
    int n = in.size();
    for (int i = from; i <= to; ++i) {
        if (maxi < in[i]) {
            maxi = in[i];
            rootIdx = i;
        }
    }
    Node* root = new Node(in[rootIdx]);
    root->left = construct(in, from, rootIdx - 1);
    root->right = construct(in, rootIdx + 1, to);
    return root;
}

void construct(vi in) {
    Node* root = construct(in, 0, in.size() - 1);
    inorder(root);
    cout << endl;
}

int main() { TimeMeasure _; __x();
    construct({5, 10, 40, 30, 28});
    construct({1, 5, 10, 40, 30, 15, 28, 20});
}
