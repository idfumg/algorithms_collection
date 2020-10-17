#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void dfs(Graph& graph, vb& visited, int at) {
    visited[at] = true;
    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            dfs(graph, visited, edge.to);
        }
    }
}

int CountNumberOfTrees(Graph& graph) {
    int n = graph.size(), count = 0;
    vb visited(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            dfs(graph, visited, i);
            ++count;
        }
    }
    return count;
}

int main() { TimeMeasure _;
    Graph graph(5);
    graph.addUndirectedEdge(0, 1);
    graph.addUndirectedEdge(0, 2);
    graph.addUndirectedEdge(3, 4);
    cout << CountNumberOfTrees(graph) << endl;
}
