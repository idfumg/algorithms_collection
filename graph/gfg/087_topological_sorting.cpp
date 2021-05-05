#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(vvvi& graph, vb& visited, vi& ordering, int& idx, int at) {
    visited[at] = true;
    for (vi adj : graph[at]) {
        if (not visited[adj[0]]) {
            dfs(graph, visited, ordering, idx, adj[0]);
        }
    }
    ordering[idx--] = at;
}

vi DFSBasedTopologicalSort(vvvi& graph) {
    int n = graph.size();
    int idx = n - 1;
    vi ordering(n);
    vb visited(n);
    for (int at = 0; at < n; ++at) {
        if (not visited[at]) {
            dfs(graph, visited, ordering, idx, at);
        }
    }
    return ordering;
}

vi DAGShortestPath(vvvi graph, vi ordering, int from) {
    int n = graph.size();
    vi dist(n, INF);
    dist[from] = 0;
    for (int at = 0; at < n; ++at) {
        if (dist[ordering[at]] == INF) continue;
        for (vi adj : graph[ordering[at]]) {
            dist[adj[0]] = min(dist[adj[0]], dist[ordering[at]] + adj[1]);
        }
    }
    return dist;
}

int main() { TimeMeasure _;
    vvvi graph(6);
    graph[0].push_back({1, 3});
    graph[0].push_back({2, 2});
    graph[0].push_back({5, 3});
    graph[1].push_back({3, 1});
    graph[1].push_back({2, 6});
    graph[2].push_back({3, 1});
    graph[2].push_back({4, 10});
    graph[3].push_back({4, 5});
    graph[5].push_back({4, 7});

    const auto ordering = DFSBasedTopologicalSort(graph);
    cout << ordering << endl; // 0, 5, 1, 2, 3, 4

    const auto distances = DAGShortestPath(graph, ordering, 0);
    cout << distances << endl; // 0 3 2 3 8 3
}
