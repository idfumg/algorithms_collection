#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

Graph Transpose(Graph& graph) {
    int n = graph.size();
    Graph newgraph(n);
    for (int i = 0; i < n; ++i) {
        for (int adj : graph[i]) {
            newgraph[adj].push_back(i);
        }
    }
    return newgraph;
}

void dfs_forward(Graph& graph, vb& visited, vector<int>& order, int at) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs_forward(graph, visited, order, adj);
        }
    }
    order.push_back(at);
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

void PrintSCCs(Graph& graph) {
    int n = graph.size();
    vector<int> order;

    vb visited(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            dfs_forward(graph, visited, order, i);
        }
    }

    visited = vb(n);
    Graph newgraph = Transpose(graph);
    for (int i = n - 1; i >= 0; --i) {
        if (not visited[order[i]]) {
            dfs_backward(newgraph, visited, order[i]);
            cout << endl;
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
}
