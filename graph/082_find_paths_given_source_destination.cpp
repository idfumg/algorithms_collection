#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

void PrintPath(vi& prev, int to) {
    vi path;
    for (int at = to; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path);
    cout << path << endl;
}

void dfs(Graph& graph, vb& visited, vi& prev, int at, int to) {
    if (at == to) {
        PrintPath(prev, to);
        return;
    }
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            prev[adj] = at;
            dfs(graph, visited, prev, adj, to);
            prev[adj] = -1;
        }
    }
    visited[at] = false;
}

void PrintAllPaths(Graph& graph, int from, int to) {
    int n = graph.size();
    vb visited(n);
    vi prev(n, -1);
    dfs(graph, visited, prev, from, to);
}

int main() { TimeMeasure _;
    Graph graph(4);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 0, 3);
    AddEdge(graph, 2, 0);
    AddEdge(graph, 2, 1);
    AddEdge(graph, 1, 3);
    PrintAllPaths(graph, 2, 3);
}
