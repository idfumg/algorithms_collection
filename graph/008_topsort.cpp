#include "../template.hpp"
#include "graph.hpp"
#include "tree_node.hpp"

// A graph a topological ordering if and only if it is a directed acyclic graph.

int dfs(const Graph& graph, vb& visited, vi& ordering, int i, int position) {
    visited[i] = true;
    for (const auto& edge : graph.neighbors(i)) {
        if (not visited[edge.to]) {
            position = dfs(graph, visited, ordering, edge.to, position);
        }
    }
    ordering[position] = i;
    return position - 1;
}

vi TopologicalSort(const Graph& graph) {
    vi ordering(graph.size());
    int position = ordering.size() - 1;
    vb visited(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
        if (not visited[i]) {
            position = dfs(graph, visited, ordering, i, position);
        }
    }
    return ordering;
}

vi DAGShortestPath(const Graph& graph, const vi& ordering, int from) {
    vi dist(graph.size(), INF);
    dist[from] = 0;
    for (int i = 0; i < graph.size(); ++i) {
        const int idx = ordering[i];
        if (dist[idx] == INF) continue;
        for (const auto& edge : graph.neighbors(idx)) {
            const int cost = edge.cost + dist[idx];
            dist[edge.to] = min(cost, dist[edge.to]);
        }
    }
    return dist;
}

int main() { TimeMeasure _;
    Graph graph(7);
    graph.addDirectedEdge(0, 1, 3);
    graph.addDirectedEdge(0, 2, 2);
    graph.addDirectedEdge(0, 5, 3);
    graph.addDirectedEdge(1, 3, 1);
    graph.addDirectedEdge(1, 2, 6);
    graph.addDirectedEdge(2, 3, 1);
    graph.addDirectedEdge(2, 4, 10);
    graph.addDirectedEdge(3, 4, 5);
    graph.addDirectedEdge(5, 4, 7);

    const auto ordering = TopologicalSort(graph);
    cout << ordering; // 6, 0, 5, 1, 2, 3, 4

    const auto distances = DAGShortestPath(graph, ordering, 0);
    cout << distances; // 0 3 2 3 8 3 1000000000
}
