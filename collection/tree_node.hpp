#include <vector>
#include <ostream>

struct TreeNode {
    int id;
    TreeNode* parent;
    vector<TreeNode*> children;

    TreeNode(int id, TreeNode* parent) : id(id), parent(parent) {}
    bool operator==(TreeNode* node) { return node and id == node->id; }
};

ostream& operator<<(ostream& os, TreeNode* node) { return os << node->id; }
