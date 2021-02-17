#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

bool IsSymmetric(Node* left, Node* right) {
    if (not left and not right) return true;
    if (not left or not right) return false;
    deque<Node*> q1, q2;
    q1.push_back(left);
    q2.push_back(right);
    while (not q1.empty() and not q2.empty()) {
        if (q1.size() != q2.size()) return false;
        int n = q1.size();
        for (int i = 0; i < n; ++i) {
            if (q1[i]->value != q2[n - i - 1]->value) return false;
        }
        while (n-- > 0) {
            Node* at1 = q1.front(); q1.pop_front();
            Node* at2 = q2.front(); q2.pop_front();
            if (at1->left and not at2->left) return false;
            if (at1->right and not at2->right) return false;
            if (at1->left) q1.push_back(at1->left);
            if (at1->right) q1.push_back(at1->right);
            if (at2->left) q2.push_back(at2->left);
            if (at2->right) q2.push_back(at2->right);
        }
    }
    return true;
}

bool IsSymmetric(Node* root) {
    if (not root) return true;
    return IsSymmetric(root->left, root->right);
}

int main() { TimeMeasure _; __x();
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    cout << IsSymmetric(root) << endl; // 1
}
