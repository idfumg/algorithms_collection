#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
}

void dfs(vvi graph, vb& visited, int at, int& handled) {
    visited[at] = true;
    ++handled;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs(graph, visited, adj, handled);
        }
    }
}

vvi transpose(vvi graph) {
    int n = graph.size();
    vvi res(n);
    for (int at = 0; at < n; ++at) {
        for (int adj : graph[at]) {
            res[adj].push_back(at);
        }
    }
    return res;
}

bool IsStronglyConnected(vvi graph) {
    int n = graph.size(), handled = 0;

    vb visited(n);
    dfs(graph, visited, 0, handled);
    if (handled != n) return false;

    graph = transpose(graph);
    handled = 0;
    visited = vb(n);
    dfs(graph, visited, 0 , handled);
    return handled == n;
}

void dfs_forward(vvi graph, vb& visited, vi& ordering, int at) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs_forward(graph, visited, ordering, adj);
        }
    }
    ordering.push_back(at);
}

void dfs_backward(vvi graph, vb& visited, int at) {
    visited[at] = true;
    cout << at << ' ';
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs_backward(graph, visited, adj);
        }
    }
}

void PrintSCCs(vvi graph) {
    int n = graph.size();

    vb visited(n);
    vi ordering;
    for (int at = 0; at < n; ++at) {
        if (not visited[at]) {
            dfs_forward(graph, visited, ordering, at);
        }
    }

    visited = vb(n);
    graph = transpose(graph);
    for (int i = n - 1; i >= 0; --i) {
        int at = ordering[i];
        if (not visited[at]) {
            dfs_backward(graph, visited, at);
            cout << endl;
        }
    }
    cout << endl;
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
        IsStronglyConnected(graph) ? cout << "Yes\n" : cout << "No\n"; // yes
    }

    {
        Graph graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        IsStronglyConnected(graph) ? cout << "Yes\n" : cout << "No\n"; // no
    }

    {
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

    {
        Graph graph(8);
        AddEdge(graph, 6, 0);
        AddEdge(graph, 6, 2);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 6, 4);
        AddEdge(graph, 2, 0);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 4, 5);
        AddEdge(graph, 5, 6);
        AddEdge(graph, 3, 7);
        AddEdge(graph, 7, 5);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 7, 3);
        AddEdge(graph, 5, 0);
        PrintSCCs(graph);
        // 3 7
        // 4 6 5
        // 0 2 1
    }
}
