#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

vi FindTreeCenters(const Graph& graph) {
    vi leaves, degree(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        degree[i] = graph.edges(i).size();
        if (degree[i] <= 1) {
            leaves.push_back(i);
            degree[i] = 0;
        }
    }
    int total = leaves.size();
    while (total < graph.size()) {
        vi newleaves;
        for (auto leaf : leaves) {
            for (const auto& edge : graph.edges(leaf)) {
                if (--degree[edge.to] == 1) {
                    newleaves.push_back(edge.to);
                }
            }
        }
        leaves = newleaves;
        total += leaves.size();
    }
    return leaves;
}

TreeNode* BuildTree(const Graph& graph, TreeNode* node) {
    for (const auto& edge : graph.edges(node->id)) {
        if (node->parent && node->parent->id == edge.to) continue;
        TreeNode* child = new TreeNode(edge.to, node);
        node->children.push_back(child);
        BuildTree(graph, child);
    }
    return node;
}

TreeNode* RootTree(const Graph& graph, int rootId) {
    return BuildTree(graph, new TreeNode(rootId, nullptr));
}

string EncodeTree(TreeNode* root) {
    if (not root) return "";
    vector<string> labels;
    for (const auto& child : root->children) {
        labels.push_back(EncodeTree(child));
    }
    sort(labels);
    string res;
    for (const auto& label : labels) {
        res += label;
    }
    return "(" + res + ")";
}

bool TreesAreIsomorphic(const Graph& tree1, const Graph& tree2) {
    const auto centers1 = FindTreeCenters(tree1);
    const auto centers2 = FindTreeCenters(tree2);
    const auto root1 = RootTree(tree1, centers1[0]);
    const auto encoded1 = EncodeTree(root1);

    for (const auto center : centers2) {
        const auto root2 = RootTree(tree2, center);
        const auto encoded2 = EncodeTree(root2);
        if (encoded1 == encoded2) return true;
    }

    return false;
}

int main() { TimeMeasure _;
    Graph tree1(5);
    tree1.addUndirectedEdge(2, 0);
    tree1.addUndirectedEdge(3, 4);
    tree1.addUndirectedEdge(2, 1);
    tree1.addUndirectedEdge(2, 3);

    Graph tree2(5);
    tree2.addUndirectedEdge(1, 0);
    tree2.addUndirectedEdge(2, 4);
    tree2.addUndirectedEdge(1, 3);
    tree2.addUndirectedEdge(1, 2);

    if (!TreesAreIsomorphic(tree1, tree2)) {
        cout << "Oops, these tree should be isomorphic!" << endl;
    }

    Graph tree3(10);
    tree3.addUndirectedEdge(0, 2);
    tree3.addUndirectedEdge(0, 1);
    tree3.addUndirectedEdge(0, 3);
    tree3.addUndirectedEdge(2, 6);
    tree3.addUndirectedEdge(2, 7);
    tree3.addUndirectedEdge(1, 4);
    tree3.addUndirectedEdge(1, 5);
    tree3.addUndirectedEdge(5, 9);
    tree3.addUndirectedEdge(3, 8);

    TreeNode* root3 = RootTree(tree3, 0);

    if (EncodeTree(root3) != "(((())())(()())(()))") {
        cout << ("Tree encoding is wrong: " + EncodeTree(root3)) << endl;
    }
}
