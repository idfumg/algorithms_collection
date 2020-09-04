#include "../template.hpp"
#include "graph.hpp"
#include "tree_node.hpp"

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

int main() { TimeMeasure _;
    {
        Graph graph(9);
        graph.addUndirectedEdge(0, 1);
        graph.addUndirectedEdge(2, 1);
        graph.addUndirectedEdge(2, 3);
        graph.addUndirectedEdge(3, 4);
        graph.addUndirectedEdge(5, 3);
        graph.addUndirectedEdge(2, 6);
        graph.addUndirectedEdge(6, 7);
        graph.addUndirectedEdge(6, 8);
        TreeNode* root = RootTree(graph, 6);

        cout << root << endl; // 6
        cout << root->children; // 2 7 8
        cout << root->children[0]->children; // 1 3
        cout << root->children[0]->children[0]->children; // 0
        cout << root->children[0]->children[1]->children; // 4 5
    }
}
