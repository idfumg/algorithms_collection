#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

int dfs(vvvi& graph, vi& visited, vi& ordering, int at, int pos) {
    visited[at] = true;
    for (vi& adj : graph[at]) {
        if (not visited[adj[0]]) {
            pos = dfs(graph, visited, ordering, adj[0], pos);
        }
    }
    ordering[pos] = at;
    return pos - 1;
}

vi DFSBasedTopologicalSort(vvvi& graph) {
    int n = graph.size(), pos = n - 1;
    vi visited(n), ordering(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            pos = dfs(graph, visited, ordering, i, pos);
        }
    }
    return ordering;
}

vi DAGShortestPath(vvvi& graph, const vi& ordering, int from) {
    int n = graph.size();
    vi dist(n, INF);
    dist[from] = 0;
    for (int i = 0; i < n; ++i) {
        int at = ordering[i];
        if (dist[at] == INF) continue;
        for (vi& adj : graph[at]) {
            dist[adj[0]] = min(dist[adj[0]], dist[at] + adj[1]);
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
