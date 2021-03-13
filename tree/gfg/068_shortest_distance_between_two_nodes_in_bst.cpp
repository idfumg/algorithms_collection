#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value > root->value) root->right = insert(root->right, value);
    if (value < root->value) root->left = insert(root->left, value);
    return root;
}

void inorder(Node* root, vi& in, int pivot) {
    if (not root) return;
    in.push_back(root->value);
    inorder(root->left, in, pivot);
    inorder(root->right, in, pivot);
    if (not in.empty() and in.back() != pivot) {
        in.pop_back();
    }
}

int FindLCA(vi& in1, vi& in2) {
    if (in1.size() > in2.size()) {
        swap(in1, in2);
    }
    int n = in1.size();
    for (int i = 0; i < n; ++i) {
        if (in1[i] != in2[i]) {
            return i - 1;
        }
    }
    return n - 1;
}

int FindDistance(Node* root, int from, int to) {
    vi in1, in2;
    inorder(root, in1, from);
    inorder(root, in2, to);
    int lca = FindLCA(in1, in2);
    return in1.size() + in2.size() - 2 * lca - 2;
}

int main() { TimeMeasure _; __x();
    {
        Node* root = nullptr;
        root = insert(root, 20);
        root = insert(root, 10);
        root = insert(root, 5);
        root = insert(root, 15);
        root = insert(root, 30);
        root = insert(root, 25);
        root = insert(root, 35);
        cout << FindDistance(root, 5, 35) << endl; // 4
    }
    {
        Node* root = new Node(5);
        root->left = new Node(2);
        root->left->left = new Node(1);
        root->left->right = new Node(3);
        root->right = new Node(12);
        root->right->left = new Node(9);
        root->right->right = new Node(21);
        root->right->right->left = new Node(19);
        root->right->right->right = new Node(25);
        cout << FindDistance(root, 3, 9) << endl; // 4
        cout << FindDistance(root, 9, 25) << endl; // 3
        cout << FindDistance(root, 12, 21) << endl; // 1
    }
}
