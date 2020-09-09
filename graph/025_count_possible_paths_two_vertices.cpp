#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void dfs(Graph& graph, vb& visited, int at, int to, int& count) {
    visited[at] = true;
    for (const auto& edge : graph.edges(at)) {
        if (edge.to == to) {
            ++count;
        }
        if (not visited[edge.to]) {
            dfs(graph, visited, edge.to, to, count);
        }
    }
}

int HowManyPaths(Graph& graph, int from, int to) {
    int n = size(graph), count = 0;
    vb visited(n);
    dfs(graph, visited, from, to, count);
    return count;
}

int main() { TimeMeasure _;
    Graph g(5);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 2);
    g.addDirectedEdge(0, 3);
    g.addDirectedEdge(1, 3);
    g.addDirectedEdge(2, 3);
    g.addDirectedEdge(1, 4);
    g.addDirectedEdge(2, 4);
    cout << HowManyPaths(g, 0, 3) << endl; // 3
}
