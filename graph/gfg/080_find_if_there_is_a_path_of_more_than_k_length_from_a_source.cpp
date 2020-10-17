#include "../../template.hpp"

using Graph = vvvi;

void AddEdge(Graph& graph, int from, int to, int weight) {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}

bool dfs(Graph& graph, vb& visited, int at, int k) {
    if (k < 0) return true;
    for (vi& adj : graph[at]) {
        if (not visited[adj[0]]) {
            visited[adj[0]] = true;
            if (dfs(graph, visited, adj[0], k - adj[1])) return true;
            visited[adj[0]] = false;
        }
    }
    return false;
}

bool PathMoreThanK(Graph& graph, int from, int k) {
    int n = graph.size();
    vb visited(n);
    return dfs(graph, visited, from, k);
}

int main() { TimeMeasure _;
    Graph graph(9);
    AddEdge(graph, 0, 1, 4);
    AddEdge(graph, 0, 7, 8);
    AddEdge(graph, 1, 2, 8);
    AddEdge(graph, 1, 7, 11);
    AddEdge(graph, 2, 3, 7);
    AddEdge(graph, 2, 8, 2);
    AddEdge(graph, 2, 5, 4);
    AddEdge(graph, 3, 4, 9);
    AddEdge(graph, 3, 5, 14);
    AddEdge(graph, 4, 5, 10);
    AddEdge(graph, 5, 6, 2);
    AddEdge(graph, 6, 7, 1);
    AddEdge(graph, 6, 8, 6);
    AddEdge(graph, 7, 8, 7);

    PathMoreThanK(graph, 0, 62) ? cout << "Yes\n" : cout << "No\n"; // no
    PathMoreThanK(graph, 0, 60) ? cout << "Yes\n" : cout << "No\n"; // yes
}
