#include "../template.hpp"

using Graph = vvvi;

void AddDirectedEdge(Graph& graph, int from, int to, int weight) {
    graph[from].push_back({to, weight});
}

vi DAGShortestPath(Graph& graph, const vi& ordering, int from) {
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

int dfs(Graph& graph, vb& visited, vi& ordering, int at, int pos) {
    visited[at] = true;
    for (vi& adj : graph[at]) {
        if (not visited[adj[0]]) {
            pos = dfs(graph, visited, ordering, adj[0], pos);
        }
    }
    ordering[pos] = at;
    return pos - 1;
}

vi DFSBasedTopologicalSort(Graph& graph) {
    int n = graph.size(), pos = n - 1;
    vi ordering(n);
    vb visited(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            pos = dfs(graph, visited, ordering, i, pos);
        }
    }
    return ordering;
}

vi KhansTopologicalSort(Graph& graph) {
    int n = graph.size();
    vi ordering, indegree(n);
    qi q;
    for (int i = 0; i < n; ++i) {
        for (vi& adj : graph[i]) {
            ++indegree[adj[0]];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    while (not q.empty()) {
        int at = q.front(); q.pop();
        ordering.push_back(at);
        for (vi& adj : graph[at]) {
            if (--indegree[adj[0]] == 0) {
                q.push(adj[0]);
            }
        }
    }
    return ordering;
}

int main() { TimeMeasure _;
    Graph graph(6);
    AddDirectedEdge(graph, 0, 1, 3);
    AddDirectedEdge(graph, 0, 2, 2);
    AddDirectedEdge(graph, 0, 5, 3);
    AddDirectedEdge(graph, 1, 3, 1);
    AddDirectedEdge(graph, 1, 2, 6);
    AddDirectedEdge(graph, 2, 3, 1);
    AddDirectedEdge(graph, 2, 4, 10);
    AddDirectedEdge(graph, 3, 4, 5);
    AddDirectedEdge(graph, 5, 4, 7);

    const auto ordering = DFSBasedTopologicalSort(graph);
    cout << ordering << endl; // 0, 5, 1, 2, 3, 4

    const auto distances = DAGShortestPath(graph, ordering, 0);
    cout << distances << endl; // 0 3 2 3 8 3
}
