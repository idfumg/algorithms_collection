#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

vi RootsForMinimumHeights(Graph& graph) {
    int n = size(graph);
    vi degree(n), leaves;
    for (int i = 0; i < n; ++i) {
        degree[i] = graph.edges(i).size();
        if (degree[i] <= 1) {
            leaves.push_back(i);
            degree[i] = 0;
        }
    }
    int total = size(leaves);
    while (total != n) {
        vi temp;
        for (const auto& leaf : leaves) {
            for (const auto& edge : graph.edges(leaf)) {
                --degree[edge.to];
                if (degree[edge.to] == 1) {
                    temp.push_back(edge.to);
                }
            }
        }
        leaves = temp;
        total += size(leaves);
    }
    return leaves;
}

int main() { TimeMeasure _;
    Graph g(6);
    g.addUndirectedEdge(0, 3);
    g.addUndirectedEdge(1, 3);
    g.addUndirectedEdge(2, 3);
    g.addUndirectedEdge(4, 3);
    g.addUndirectedEdge(5, 4);
    cout << RootsForMinimumHeights(g) << endl;
}
