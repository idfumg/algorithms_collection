#include <vector>
#include <ostream>

struct TreeNode {
    int id;
    TreeNode* parent;
    std::vector<TreeNode*> children;

    TreeNode(const TreeNode& rhs) noexcept
        : id(rhs.id), parent(rhs.parent), children(rhs.children)
    {
    }
    TreeNode(const int id_, TreeNode* parent_) noexcept
        : id(id_), parent(parent_), children()
    {
    }
    bool operator==(const TreeNode* node) const noexcept
    {
        return node and id == node->id;
    }
    TreeNode& operator=(const TreeNode& rhs) noexcept
    {
        id = rhs.id;
        parent = rhs.parent;
        children = rhs.children;
        return *this;
    }
};

std::ostream& operator<<(std::ostream& os, const TreeNode* node) noexcept {
    if (node) return os << node->id;
    return os;
}
