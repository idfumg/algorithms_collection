#include "../../template.hpp"

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) : value(value), left(nullptr), right(nullptr) {}
};

void Inorder(Node* root) {
    if (not root) return;
    Inorder(root->left);
    cout << root->value << ' ';
    Inorder(root->right);
}

vi MakeLevelorder(vi inorder, vi levelorder, int from, int to) {
    vi ans;
    for (int v : levelorder) {
        for (int i = from; i <= to; ++i) {
            if (inorder[i] == v) {
                ans.push_back(v);
            }
        }
    }
    return ans;
}

Node* Make(vi inorder, vi levelorder, int i, int j) {
    if (i > j) return nullptr;

    int inidx = i;
    for (; inidx <= j and inorder[inidx] != levelorder[0]; ++inidx);

    Node* root = new Node(levelorder[0]);
    root->left = Make(inorder, MakeLevelorder(inorder, levelorder, i, inidx - 1), i, inidx - 1);
    root->right = Make(inorder, MakeLevelorder(inorder, levelorder, inidx +1, j), inidx + 1, j);
    return root;
}

void Construct(vi inorder, vi levelorder) {
    Node* node = Make(inorder, levelorder, 0, inorder.size() - 1);
    Inorder(node);
}

int main() { TimeMeasure _; __x();
    vi inorder = {4, 8, 10, 12, 14, 20, 22};
    vi levelorder = {20, 8, 22, 4, 12, 10, 14};
    Construct(inorder, levelorder);
}
