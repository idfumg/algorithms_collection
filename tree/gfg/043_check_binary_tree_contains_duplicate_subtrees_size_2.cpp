#include "../../template.hpp"

struct Node {
    char value = -100;
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

void getSubtree(Node* root, string& subtree) {
    if (not root) return;
    subtree += root->value;
    getSubtree(root->left, subtree);
    getSubtree(root->right, subtree);
}

bool traverse(Node* root, unordered_set<string>& subtrees) {
    if (not root) return false;

    string subtree;
    getSubtree(root, subtree);
    if (subtree.size() >= 2) {
        if (subtrees.count(subtree)) return true;
        else subtrees.insert(subtree);
    }

    return traverse(root->left, subtrees) or traverse(root->right, subtrees);
}

bool HasDuplicateSubTree(Node* root) {
    unordered_set<string> subtrees;
    return traverse(root, subtrees);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');
    root->right->right = new Node('B');
    root->right->right->right = new Node('E');
    root->right->right->left= new Node('D');

    cout << HasDuplicateSubTree(root) << endl; // 1
}
