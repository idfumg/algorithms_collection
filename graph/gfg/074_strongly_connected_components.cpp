#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

void dfs_forward(Graph& graph, vb& visited, vi& ordering, int at) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs_forward(graph, visited, ordering, adj);
        }
    }
    ordering.push_back(at);
}

void dfs_backward(Graph& graph, vb& visited, int at) {
    visited[at] = true;
    cout << at << ' ';
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs_backward(graph, visited, adj);
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

void PrintSCCs(Graph& graph) {
    int n = graph.size();

    vb visited(n);
    vi ordering;
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            dfs_forward(graph, visited, ordering, i);
        }
    }

    visited = vb(n);
    Graph transposed = Transpose(graph);
    for (int i = n - 1; i >= 0; --i) {
        if (not visited[ordering[i]]) {
            dfs_backward(transposed, visited, ordering[i]);
            cout << '\n';
        }
    }
}

int main() { TimeMeasure _;
    Graph graph(5);
    AddEdge(graph, 1, 0);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 2, 1);
    AddEdge(graph, 0, 3);
    AddEdge(graph, 3, 4);
    PrintSCCs(graph);
// 0 1 2
// 3
// 4
}
