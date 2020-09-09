#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool dfs(Graph& graph, int at, vb& visited, int to) {
    visited[at] = true;
    for (const auto& edge : graph.edges(at)) {
        if (edge.to == to) return true;
        if (not visited[edge.to]) {
            if (dfs(graph, edge.to, visited, to)) return true;
        }
    }
    return false;
}

bool IsReachable(Graph& graph, int from, int to) {
    int n = graph.size();
    vb visited(n);
    return dfs(graph, from, visited, to);
}

int main() { TimeMeasure _;
    int n = 4;
    Graph graph(4);
    graph.addDirectedEdge(0, 1);
    graph.addDirectedEdge(0, 2);
    graph.addDirectedEdge(1, 2);
    graph.addDirectedEdge(2, 0);
    graph.addDirectedEdge(2, 3);
    graph.addDirectedEdge(3, 3);
    cout << IsReachable(graph, 1, 3) << endl;
    cout << IsReachable(graph, 3, 1) << endl;
}
