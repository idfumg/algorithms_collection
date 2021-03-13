#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

void inorder(Node* root, unordered_map<int, int>& map) {
    if (not root) return;
    inorder(root->left, map);
    ++map[root->value];
    inorder(root->right, map);
}

int CountPairs(Node* root1, Node* root2, int x) {
    unordered_map<int, int> map1, map2;
    inorder(root1, map1);
    inorder(root2, map2);

    int ans = 0;
    for (const auto& [key, count] : map1) {
        int diff = x - key;
        if (map2.count(diff)) {
            cout << key << ' ' << diff << endl;
            ++ans;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    cout << CountPairs(root1, root2, 16) << endl; // 3
}
