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

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (value > root->value) root->right = insert(root->right, value);
    if (value < root->value) root->left = insert(root->left, value);
    return root;
}

Node* RemoveOutsideRange(Node* root, int x, int y) {
    if (not root) return nullptr;
    root->left = RemoveOutsideRange(root->left, x, y);
    root->right = RemoveOutsideRange(root->right, x, y);
    if (root->value < x) {
        Node* temp = root;
        root = root->right;
        delete temp;
    }
    else if (root->value > y) {
        Node* temp = root;
        root = root->left;
        delete temp;
    }
    return root;
}

Node* Delete(Node* root, int value) {
    if (not root) {
        return nullptr;
    }

    if (not root->left) {
        Node* temp = root->right;
        delete root;
        return temp;
    }

    if (not root->right) {
        Node* temp = root->left;
        delete root;
        return temp;
    }

    Node* curr = root->right;
    for (; curr and curr->left; curr = curr->left);
    swap(curr->value, root->value);
    root->right = Delete(root->right, value);
    return root;
}

void preorder(Node* root, int from, int to) {
    if (not root) {
        return;
    }
    while (root->left and (root->left->value < from or root->left->value > to)) {
        root->left = Delete(root->left, root->left->value);
    }
    while (root->right and (root->right->value < from or root->right->value > to)) {
        root->right = Delete(root->right, root->right->value);
    }
    preorder(root->left, from, to);
    preorder(root->right, from, to);
}

Node* RemoveOutsideRange2(Node* root, int from, int to) {
    if (root->value < from or root->value > to) {
        delete root;
        return nullptr;
    }
    preorder(root, from, to);
    return root;
}


int main() { TimeMeasure _; __x();
    {
        Node* root = nullptr;
        root = insert(root, 6);
        root = insert(root, -13);
        root = insert(root, 14);
        root = insert(root, -8);
        root = insert(root, 15);
        root = insert(root, 13);
        root = insert(root, 7);

        inorder(root); cout << endl; // -13 -8 6 7 13 14 15
        root = RemoveOutsideRange(root, -10, 13);
        inorder(root); cout << endl; // -8 6 7 13
    }
    {
        Node* root = nullptr;
        root = insert(root, 6);
        root = insert(root, -13);
        root = insert(root, 14);
        root = insert(root, -8);
        root = insert(root, 15);
        root = insert(root, 13);
        root = insert(root, 7);

        inorder(root); cout << endl; // -13 -8 6 7 13 14 15
        root = RemoveOutsideRange2(root, -10, 13);
        inorder(root); cout << endl; // -8 6 7 13
    }
}
