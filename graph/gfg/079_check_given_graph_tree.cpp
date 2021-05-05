#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool dfs(vvi graph, vb& visited, int at, int parent, int& handled) {
    visited[at] = true;
    ++handled;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        if (visited[adj]) return true;
        if (dfs(graph, visited, adj, at, handled)) return true;
    }
    return false;
}

bool IsTree(vvi graph) {
    int n = graph.size();
    int handled = 0;
    vb visited(n);
    if (dfs(graph, visited, 0, -1, handled)) return false;
    if (handled != n) return false;
    return true;
}

int main() { TimeMeasure _;
    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        IsTree(graph) ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n"; // 1
    }

    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        IsTree(graph) ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n"; // 0
    }
}
