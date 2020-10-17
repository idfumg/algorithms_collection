#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

Graph CreateGraph(vi& arr) {
    int n = arr.size();
    Graph graph(n);
    for (int i = 0; i < n; ++i) {
        AddEdge(graph, i, (arr[i] + i + 1) % n);
    }
    return graph;
}

void dfs_forward(Graph& graph, vb& visited, vi& path, int at) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs_forward(graph, visited, path, adj);
        }
    }
    path.push_back(at);
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

int dfs_backward(Graph& graph, vb& visited, int at) {
    visited[at] = true;
    int count = 1;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            count += dfs_backward(graph, visited, adj);
        }
    }
    return count;
}

int FindSCC(Graph& graph) {
    int n = graph.size();

    vb visited(n);
    vi path;
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            dfs_forward(graph, visited, path, i);
        }
    }

    int count = 0;
    visited = vb(n);
    Graph transposed = Transpose(graph);
    for (int i = n - 1; i >= 0; --i) {
        if (not visited[path[i]]) {
            int res = dfs_backward(transposed, visited, path[i]);
            if (res > 1) {
                count += res;
            }
        }
    }

    return count;
}

int FindSelfLoops(vi& arr) {
    int count = 0, n = arr.size();
    for (int i = 0; i < n; ++i) {
        if ((i + arr[i] + 1) % n == i) {
            ++count;
        }
    }
    return count;
}

int CountCyclicElements(vi& arr) {
    Graph graph = CreateGraph(arr);
    return FindSCC(graph) + FindSelfLoops(arr);
}

int main() { TimeMeasure _;
    vi arr1 = {1, 1, 1, 1};
    vi arr2 = {3, 0, 0, 0};
    cout << CountCyclicElements(arr1) << endl;
    cout << CountCyclicElements(arr2) << endl;
}
