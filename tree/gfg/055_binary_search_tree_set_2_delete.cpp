#include "../../template.hpp"

struct Node {
    int value = -100;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void Inorder(Node* root) {
    if (not root) return;
    Inorder(root->left);
    cout << root->value << ' ';
    Inorder(root->right);
}

// Node* Insert(Node* root, int value) {
//     if (not root) return new Node(value);
//     if (value > root->value) root->right = Insert(root->right, value);
//     else if (value < root->value) root->left = Insert(root->left, value);
//     return root;
// }

// Node* Search(Node* root, int value) {
//     if (not root) return nullptr;
//     if (root->value == value) return root;
//     if (value < root->value) return Search(root->left, value);
//     return Search(root->right, value);
// }

Node* Insert(Node* root, int value) {
    if (not root) return new Node(value);
    Node* curr = root;
    while (curr) {
        if (curr->value < value) {
            if (not curr->right) {
                curr->right = new Node(value);
                break;
            }
            curr = curr->right;
        }
        else if (curr->value > value) {
            if (not curr->left) {
                curr->left = new Node(value);
                break;
            }
            curr = curr->left;
        }
        else {
            break;
        }
    }
    return root;
}

Node* Search(Node* root, int value) {
    Node* curr = root;
    while (curr) {
        if (curr->value == value) return curr;
        else if (curr->value < value) curr = curr->right;
        else curr = curr->left;
    }
    return nullptr;
}

Node* Delete(Node* root, int value) {
    if (not root) {
        return root;
    }

    if (root->value > value) {
        root->left = Delete(root->left, value);
        return root;
    }

    if (root->value < value) {
        root->right = Delete(root->right, value);
        return root;
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
    while (curr and curr->left) {
        curr = curr->left;
    }
    swap(curr->value, root->value);
    root->right = Delete(root->right, value);
    return root;
}

int main() { TimeMeasure _; __x();
    /* Create following BST
      50
    /    \
   30    70
  / \    / \
20  40  60 80 */

    Node* root = nullptr;
    root = Insert(root, 50);
    root = Insert(root, 30);
    root = Insert(root, 20);
    root = Insert(root, 40);
    root = Insert(root, 70);
    root = Insert(root, 60);
    root = Insert(root, 80);

    Inorder(root); cout << endl; // 20 30 40 50 60 70 80

    cout << Search(root, 60)->value << endl; // 60

    root = Delete(root, 20);
    Inorder(root);  cout << endl; // 30 40 50 60 70 80

    root = Delete(root, 30);
    Inorder(root); cout << endl; // 40 50 60 70 80

    root = Delete(root, 50);
    Inorder(root); cout << endl; // 40 60 70 80
}
