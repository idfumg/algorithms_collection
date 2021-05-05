#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

bool dfs(vvi graph, vb& visited, int root, int at, int parent) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        if (adj == root) return true;
        if (not visited[adj]) {
            if (dfs(graph, visited, root, adj, at)) return true;
        }
    }
    return false;
}

void CountWeaklyConnectedComponents(vvi graph) {
    int n = graph.size();
    vb visited(n);
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            if (not dfs(graph, visited, i, i, -1)) ++count;
        }
    }
    cout << count << endl;
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
