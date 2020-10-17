#include "../../template.hpp"

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

bool IsTree(Graph& graph) {
    int n = graph.size();
    vb visited(n);
    if (dfs(graph, visited, 0, -1)) return false; // cycle detected
    return all_of(visited.begin(), visited.end(), [](bool v){return v;});
}

int main() { TimeMeasure _;
    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        IsTree(graph) ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";
    }

    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        IsTree(graph) ? cout << "Graph is Tree\n" : cout << "Graph is not Tree\n";
    }
}
