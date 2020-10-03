#include "../template.hpp"

using Graph = vvi;

void AddDirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

bool dfs(Graph& graph, int at, int to, int level) {
    if (at == to) return true;
    if (level <= 0) return false;
    for (int adj : graph[at]) {
        if (dfs(graph, adj, to, level - 1)) return true;
    }
    return false;
}

bool iddfs(Graph& graph, int from, int to, int maxlevel) {
    for (int level = 1; level <= maxlevel; ++level) {
        if (dfs(graph, from, to, level)) return true;
    }
    return false;
}

int main() { TimeMeasure _;
    Graph graph(7);
    AddDirectedEdge(graph, 0, 1);
    AddDirectedEdge(graph, 0, 2);
    AddDirectedEdge(graph, 1, 3);
    AddDirectedEdge(graph, 1, 4);
    AddDirectedEdge(graph, 2, 5);
    AddDirectedEdge(graph, 2, 6);
    cout << iddfs(graph, 0, 6, 3) << '\n';
}
