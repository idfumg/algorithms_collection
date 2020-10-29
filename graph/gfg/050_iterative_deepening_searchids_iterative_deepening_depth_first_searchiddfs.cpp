#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool dfs(Graph& graph, int at, int to, int level, int parent) {
    if (at == to) return true;
    if (level < 0) return false;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        if (dfs(graph, adj, to, level - 1, at)) return true;
    }
    return false;
}

bool iddfs(Graph& graph, int from, int to, int level) {
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        if (dfs(graph, from, to, level, -1)) {
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
