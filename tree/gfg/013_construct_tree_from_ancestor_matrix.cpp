#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void inorder(Node* root) {
    if (not root) return;
    inorder(root->left);
    cout << root->value << ' ';
    inorder(root->right);
}

Node* construct_(vvi arr) {
    int n = arr.size();

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<Node*> node(n);
    for (int i = 0; i < n; ++i) {
        int childrenCount = accumulate(arr[i].begin(), arr[i].end(), 0);
        pq.push({childrenCount, i});
        node[i] = new Node(i);
    }

    vb used(n);
    Node* root = nullptr;
    while (not pq.empty()) {
        const auto [childrenCount, at] = pq.top(); pq.pop();
        root = node[at];

        if (childrenCount == 0) {
            continue;
        }

        for (int i = 0; i < n; ++i) {
            if (not used[i] and arr[at][i]) {
                if (not node[at]->left) node[at]->left = node[i];
                else if (not node[at]->right) node[at]->right = node[i];
                used[i] = true;
            }
        }
    }
    return root;
}

void construct(vvi arr) {
    Node* root = construct_(arr);
    inorder(root);
}

int main() { TimeMeasure _; __x();
    vvi arr =
        {{ 0, 0, 0, 0, 0, 0 },
         { 1, 0, 0, 0, 1, 0 },
         { 0, 0, 0, 1, 0, 0 },
         { 0, 0, 0, 0, 0, 0 },
         { 0, 0, 0, 0, 0, 0 },
         { 1, 1, 1, 1, 1, 0 }};

    construct(arr); // 0 1 4 5 3 2
}
