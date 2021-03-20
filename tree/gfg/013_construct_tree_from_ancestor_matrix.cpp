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

Node* construct(vvi arr) {
    priority_queue<pi, vpi, greater<pi>> pq;
    int n = arr.size();
    vector<Node*> nodes(n);
    for (int i = 0; i < n; ++i) {
        int children = accumulate(arr[i].begin(), arr[i].end(), 0);
        pq.push({children, i});
        nodes[i] = new Node(i);
    }
    vb used(n);
    Node* root = nullptr;
    while (not pq.empty()) {
        const auto& [children, at] = pq.top(); pq.pop();
        root = nodes[at];
        if (children == 0) continue;
        for (int i = 0; i < n; ++i) {
            if (not used[i] and arr[at][i]) {
                used[i] = true;
                if (not nodes[at]->left) nodes[at]->left = nodes[i];
                else if (not nodes[at]->right) nodes[at]->right = nodes[i];
            }
        }
    }
    return root;
}

int main() { TimeMeasure _; __x();
    vvi arr =
        {{ 0, 0, 0, 0, 0, 0 },
         { 1, 0, 0, 0, 1, 0 },
         { 0, 0, 0, 1, 0, 0 },
         { 0, 0, 0, 0, 0, 0 },
         { 0, 0, 0, 0, 0, 0 },
         { 1, 1, 1, 1, 1, 0 }};

    Node* root = construct(arr); // 0 1 4 5 3 2
    inorder(root);
}
