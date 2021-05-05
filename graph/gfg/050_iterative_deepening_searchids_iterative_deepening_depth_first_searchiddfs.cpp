#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool dfs(vvi graph, int to, vb& visited, int parent, int depth, int at) {
    if (at == to and depth == 0) {
        return true;
    }
    visited[at] = true;
    for (int adj : graph[at]) {
        if (adj == parent) {
            continue;
        }
        if (not visited[adj]) {
            if (dfs(graph, to, visited, parent, depth - 1, adj)) {
                return true;
            }
        }
    }
    return false;
}

int iddfs(vvi graph, int from, int to, int maxdepth) {
    int n = graph.size();
    for (int depth = 1; depth < maxdepth; ++depth) {
        vb visited(n);
        if (dfs(graph, to, visited, -1, depth, from)) {
            return true;
        }
    }
    return false;
}

int main() { TimeMeasure _;
    vvi graph(7);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 5);
    AddEdge(graph, 2, 6);
    cout << iddfs(graph, 0, 6, 3) << endl; // 1
}
