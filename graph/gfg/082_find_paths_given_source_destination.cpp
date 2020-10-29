#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    //graph[to].push_back(from);
}

void PrintPath(vi& parent, int to) {
    vi path;
    for (int at = to; at != -1; at = parent[at]) {
        path.push_back(at);
    }
    reverse(path);
    cout << path << '\n';
}

void dfs(Graph& graph, vb& visited, int at, int to, vi& parent) {
    if (at == to) {
        PrintPath(parent, to);
        return;
    }
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            parent[adj] = at;
            dfs(graph, visited, adj, to, parent);
            parent[adj] = -1;
        }
    }
    visited[at] = false;
}

void PrintAllPaths(Graph& graph, int from, int to) {
    int n = graph.size();
    vb visited(n);
    vi parent(n, -1);
    dfs(graph, visited, from, to, parent);
}

void dfs2(Graph& graph, vb& visited, vi& elems, int to, int at) {
    visited[at] = true;
    elems.push_back(at);

    if (at == to) {
        cout << elems << '\n';
    }

    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs2(graph, visited, elems, to, adj);
        }
    }

    elems.pop_back();
    visited[at] = false;
}

void PrintAllPaths2(Graph& graph, int from, int to) {
    int n = graph.size();
    vb visited(n);
    vi elems;
    dfs2(graph, visited, elems, to, from);
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
    cout << '\n';
    PrintAllPaths2(graph, 2, 3);
// 2 0 1 3
// 2 0 3
// 2 1 3
}
