#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void PrintPostorder(vi inorder, vi preorder, unordered_map<int, int>& map, int& root, int i, int j) {
    if (i > j) return;
    int rootIdx = map[preorder[root++]];
    PrintPostorder(inorder, preorder, map, root, i, rootIdx - 1);
    PrintPostorder(inorder, preorder, map, root, rootIdx + 1, j);
    cout << inorder[rootIdx] << ' ';
}

void PostorderTraversal(vi inorder, vi preorder) {
    unordered_map<int, int> map;
    int n = inorder.size();
    for (int i = 0; i < n; ++i) {
        map[inorder[i]] = i;
    }
    int root = 0;
    PrintPostorder(inorder, preorder, map, root, 0, n - 1);
}

int main() { TimeMeasure _; __x();
    vi inorder = {4, 2, 5, 1, 3, 6};
    vi preorder = {1, 2, 4, 5, 3, 6};
    PostorderTraversal(inorder, preorder); // 4 5 2 6 3 1
}
