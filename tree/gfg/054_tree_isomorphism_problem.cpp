#include "../../template.hpp"

struct Node {
    int value = INF;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int value) : value(value) {}
};

string EncodeTree(Node* root) {
    if (not root) return "";

    vector<string> labels;
    if (root->left) labels.push_back(EncodeTree(root->left));
    if (root->right) labels.push_back(EncodeTree(root->right));

    sort(labels.begin(), labels.end());

    string ans;
    for (const auto& label : labels) {
        ans += label;
    }
    return "(" + ans + ")";
}

bool IsIsomorphic(Node* root1, Node* root2) {
    const auto encoded1 = EncodeTree(root1);
    const auto encoded2 = EncodeTree(root2);
    return encoded1 == encoded2;
}

int main() { TimeMeasure _; __x();
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->right->left = new Node(6);
    root1->left->right->left = new Node(7);
    root1->left->right->right = new Node(8);

    Node *root2 = new Node(1);
    root2->left = new Node(3);
    root2->right = new Node(2);
    root2->right->left = new Node(4);
    root2->right->right = new Node(5);
    root2->left->right = new Node(6);
    root2->right->right->left = new Node(8);
    root2->right->right->right = new Node(7);

    cout << IsIsomorphic(root1, root2) << endl;
}
