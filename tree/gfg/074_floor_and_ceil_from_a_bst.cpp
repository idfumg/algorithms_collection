#include "../../template.hpp"

ostream& operator<<(ostream& os, Node* root) { print_inorder(root); return os; }

void inorder(Node* root, int key, int& mini, int& maxi) {
    if (not root) return;
    if (key <= root->value) inorder(root->left, key, mini, maxi);
    if (root->value >= key and root->value < maxi) maxi = root->value;
    if (root->value <= key and root->value > mini) mini = root->value;
    if (key >= root->value) inorder(root->right, key, mini, maxi);
}

void FloorAndCeilOfBST(Node* root, int key) {
    int mini = -INF;
    int maxi = +INF;
    inorder(root, key, mini, maxi);
    debug(mini); debugn(maxi);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    FloorAndCeilOfBST(root, 11); // 10 12
    FloorAndCeilOfBST(root, 1); // -1 2
    FloorAndCeilOfBST(root, 6); // 6 6
    FloorAndCeilOfBST(root, 15); // 14 -1
}
