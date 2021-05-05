#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

void dfs(vvi graph, vb& visited, int at, int k) {
    if (k == -1) return;
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs(graph, visited, adj, k - 1);
        }
    }
}

int FindKDistance(vvi graph, vi terminals, int k) {
    int n = graph.size();
    vb marked(n, true);
    for (int terminal : terminals) {
        vb visited(n);
        dfs(graph, visited, terminal, k);
        for (int i = 0; i < n; ++i) {
            marked[i] = marked[i] and visited[i];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (marked[i]) {
            cout << i << ' ';
            ++ans;
        }
    }
    cout << endl;
    return ans;
}

int main() { TimeMeasure _;
    Graph graph(10);
    AddEdge(graph, 1, 0);
    AddEdge(graph, 0, 8);
    AddEdge(graph, 0, 3);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 6);
    AddEdge(graph, 3, 7);
    AddEdge(graph, 3, 5);
    AddEdge(graph, 4, 5);
    AddEdge(graph, 5, 9);
    cout << FindKDistance(graph, {1, 2, 4}, 3) << endl;
}
