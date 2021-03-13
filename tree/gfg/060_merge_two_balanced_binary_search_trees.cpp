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

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (root->value > value) root->left = insert(root->left, value);
    else if (root->value < value) root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root, vi& arr) {
    if (not root) return;
    inorder(root->left, arr);
    arr.push_back(root->value);
    inorder(root->right, arr);
}


Node* MergeTrees(Node* root1, Node* root2) {
    vi arr1;
    inorder(root1, arr1);

    vi arr2;
    inorder(root2, arr2);

    if (arr1.size() > arr2.size()) swap(arr1, arr2);

    int m = arr1.size();
    int n = arr2.size();

    int i = 0;
    int j = 0;

    Node* root = nullptr;

    while (i < m and j < n) {
        if (arr1[i] < arr2[j]) root = insert(root, arr1[i++]);
        else root = insert(root, arr2[j++]);
    }
    while (i < m) root = insert(root, arr1[i++]);
    while (j < n) root = insert(root, arr2[j++]);

    return root;
}

int main() { TimeMeasure _; __x();
/*
     100
    /  \
  50   300
 /  \
20  70
*/
    Node* root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

/*
    80
   /  \
  40  120
*/
    Node* root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    Node* mergedTree = MergeTrees(root1, root2);
    inorder(mergedTree); // 20 40 50 70 80 100 120 300
}
