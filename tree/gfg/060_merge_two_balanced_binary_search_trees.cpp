#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

Node* insert(Node* root, int value) {
    if (not root) return new Node(value);
    if (root->value > value) root->left = insert(root->left, value);
    if (root->value < value) root->right = insert(root->right, value);
    return root;
}

void inorder(Node* root, vi& in) {
    if (not root) return;
    inorder(root->left, in);
    in.push_back(root->value);
    inorder(root->right, in);
}

int find_mid(vi arr, int i, int j) {
    return i + (j - i) / 2;
}

Node* construct(vi arr, int i, int j) {
    if (i >= j) return nullptr;
    int mid = find_mid(arr, i, j);
    Node* root = new Node(arr[mid]);
    root->left = construct(arr, i, mid);
    root->right = construct(arr, mid + 1, j);
    return root;
}

Node* MergeTrees(Node* root1, Node* root2) {
    vi in1, in2;
    inorder(root1, in1);
    inorder(root2, in2);

    int k = 0, i = 0, j = 0, m = in1.size(), n = in2.size();
    vi in(m + n);
    while (i < m and j < n) {
        if (in1[i] < in2[j]) in[k++] = in1[i++];
        else in[k++] = in2[j++];
    }
    while (i < m) in[k++] = in1[i++];
    while (j < n) in[k++] = in2[j++];

    return construct(in, 0, in.size());
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
    cout << mergedTree << endl; // 20 40 50 70 80 100 120 300
}
