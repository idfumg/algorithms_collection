#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

void dfs(Graph& graph, vb& visited, int at) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs(graph, visited, adj);
        }
    }
}

Graph Transpose(Graph& graph) {
    int n = graph.size();
    Graph newgraph(n);
    for (int i = 0; i < n; ++i) {
        for (int adj : graph[i]) {
            AddEdge(newgraph, adj, i);
        }
    }
    return newgraph;
}

bool IsStronglyConnected(Graph& graph) {
    int n = graph.size();

    vb visited(n);
    dfs(graph, visited, 0);
    if (any_of(visited.begin(), visited.end(),[](bool v){return !v;}))return false;

    visited = vb(n);
    Graph transposed = Transpose(graph);
    dfs(transposed, visited, 0);
    return !any_of(visited.begin(), visited.end(), [](bool v){return !v;});
}

int main() { TimeMeasure _;
    {
        Graph graph(5);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        AddEdge(graph, 3, 0);
        AddEdge(graph, 2, 4);
        AddEdge(graph, 4, 2);
        IsStronglyConnected(graph) ? cout << "Yes\n" : cout << "No\n";
    }

    {
        Graph graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        IsStronglyConnected(graph) ? cout << "Yes\n" : cout << "No\n";
    }
}
