#include "../template.hpp"

using Graph = vvi;

void AddUndirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void AddDirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

bool dfs(Graph& graph, vb& visited, int at, int parent) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        if (visited[adj]) return true;
        if (dfs(graph, visited, adj, at)) return true;
    }
    return false;
}

bool DetectCycle(Graph& graph) {
    int n = graph.size();
    vb visited(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            if (dfs(graph, visited, i, -1)) return true;
        }
    }
    return false;
}

int main() { TimeMeasure _;
    {
        Graph graph(4);
        AddUndirectedEdge(graph, 0, 1);
        AddUndirectedEdge(graph, 1, 2);
        AddUndirectedEdge(graph, 2, 3);
        AddUndirectedEdge(graph, 0, 2);
        cout << DetectCycle(graph) << '\n'; // yes
    }
    {
        Graph graph(4);
        AddUndirectedEdge(graph, 0, 1);
        AddUndirectedEdge(graph, 1, 2);
        AddUndirectedEdge(graph, 2, 3);
        cout << DetectCycle(graph) << '\n'; // no
    }
    {
        Graph graph(5);
        AddUndirectedEdge(graph, 1, 0);
        AddUndirectedEdge(graph, 0, 2);
        AddUndirectedEdge(graph, 2, 1);
        AddUndirectedEdge(graph, 0, 3);
        AddUndirectedEdge(graph, 3, 4);
        cout << DetectCycle(graph) << '\n'; // yes
    }
}
