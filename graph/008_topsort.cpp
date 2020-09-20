#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

vi DAGShortestPath2(vvvi& graph, const vi& ordering, int from) {
    int n = graph.size();
    vi dist(n, INF);
    dist[from] = 0;
    for (int at = 0; at < n; ++at) {
        int idx = ordering[at];
        if (dist[idx] == INF) continue;
        for (vi adj : graph[idx]) {
            dist[adj[0]] = min(dist[adj[0]], dist[idx] + adj[1]);
        }
    }
    return dist;
}

vi TopologicalSort2(vvvi& graph) {
    int n = size(graph);

    vi indegree(n);
    for (int i = 0; i < n; ++i) {
        for (vi adj : graph[i]) {
            ++indegree[adj[0]];
        }
    }

    qi q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    vi ordering;
    while (not q.empty()) {
        int at = q.front(); q.pop();
        ordering.push_back(at);
        for (vi adj : graph[at]) {
            if (--indegree[adj[0]] == 0) {
                q.push(adj[0]);
            }
        }
        ++count;
    }

    if (count != n) {
        cout << "Cycle detected!" << endl;
        return {};
    }

    return ordering;
}

int dfs(Graph& graph, vi& ordering, vb& visited, int pos, int at) {
    visited[at] = true;
    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            pos = dfs(graph, ordering, visited, pos, edge.to);
        }
    }
    ordering[pos] = at;
    return pos - 1;
}

vi TopologicalSort(Graph& graph) {
    int n = graph.size(), pos = n - 1;
    vi ordering(n);
    vb visited(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            pos = dfs(graph, ordering, visited, pos, i);
        }
    }
    return ordering;
}

vi DAGShortestPath(Graph& graph, const vi& ordering, int from) {
    int n = graph.size();
    vi dist(n, INF);
    dist[from] = 0;
    for (int at = 0; at < n; ++at) {
        int idx = ordering[at];
        if (dist[idx] == INF) continue;
        for (const auto& edge : graph.edges(idx)) {
            dist[edge.to] = min(dist[edge.to], edge.cost + dist[idx]);
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
    cout << ordering << endl; // 6, 0, 5, 1, 2, 3, 4

    const auto distances = DAGShortestPath(graph, ordering, 0);
    cout << distances << endl; // 0 3 2 3 8 3 1000000000

    vvvi graph2(7);
    graph2[0].push_back({1, 3});
    graph2[0].push_back({2, 2});
    graph2[0].push_back({5, 3});
    graph2[1].push_back({3, 1});
    graph2[1].push_back({2, 6});
    graph2[2].push_back({3, 1});
    graph2[2].push_back({4, 10});
    graph2[3].push_back({4, 5});
    graph2[5].push_back({4, 7});

    const auto ordering2 = TopologicalSort2(graph2);
    cout << ordering2 << endl; // 0 6 1 5 2 3 4

    const auto distances2 = DAGShortestPath2(graph2, ordering, 0);
    cout << distances2 << endl; // 0 3 2 3 8 3 1000000000
}
