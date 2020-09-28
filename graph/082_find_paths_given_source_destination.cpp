#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

void PrintPath(vi& parent, int to) {
    vi path;
    for (int at = to; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path);
    cout << path << endl;
}

void dfs(Graph& graph, vb& visited, vi& parent, int at, int to) {
    if (at == to) {
        PrintPath(parent, to);
        return;
    }

    for (int adj : graph[at]) {
        if (not visited[adj]) {
            parent[adj] = at;
            visited[at] = true;
            dfs(graph, visited, parent, adj, to);
            parent[adj] = -1;
            visited[at] = false;
        }
    }
}

void PrintAllPaths(Graph& graph, int from, int to) {
    int n = graph.size();
    vb visited(n);
    vi parent(n, -1);
    visited[from] = true;
    dfs(graph, visited, parent, from, to);
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
