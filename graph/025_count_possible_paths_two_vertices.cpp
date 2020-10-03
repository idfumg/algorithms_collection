#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

void dfs(Graph& graph, vb& visited, int at, int to, int& count) {
    if (at == to) {
        ++count;
        return;
    }
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            visited[adj] = true;
            dfs(graph, visited, adj, to, count);
            visited[adj] = false;
        }
    }
}

int HowManyPaths(Graph& graph, int from, int to) {
    int n = graph.size(), count = 0;
    vb visited(n);
    dfs(graph, visited, from, to, count);
    return count;
}

int main() { TimeMeasure _;
    Graph g(5);
    AddEdge(g, 0, 1);
    AddEdge(g, 0, 2);
    AddEdge(g, 0, 3);
    AddEdge(g, 1, 3);
    AddEdge(g, 2, 3);
    AddEdge(g, 1, 4);
    AddEdge(g, 2, 4);
    cout << HowManyPaths(g, 0, 3) << '\n'; // 3
}
