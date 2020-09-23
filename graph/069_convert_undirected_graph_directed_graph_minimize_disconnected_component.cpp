#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool dfs(Graph& graph, vb& visited, int at, int parent) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        if (visited[adj]) return true;
        if (dfs(graph, visited, adj, at)) return true;
    }
    return false;
}

void CountWeaklyConnectedComponents(Graph& graph) {
    int n = graph.size(), count = 0;
    vb visited(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            if (not dfs(graph, visited, i, -1)) ++count; // no cycle
        }
    }
    debugn(count);
}

int main() { TimeMeasure _;
    {
        Graph graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        AddEdge(graph, 3, 0);
        CountWeaklyConnectedComponents(graph);
    }
    {
        Graph graph(7);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        AddEdge(graph, 4, 5);
        AddEdge(graph, 4, 6);
        AddEdge(graph, 5, 6);
        CountWeaklyConnectedComponents(graph);
    }
}
