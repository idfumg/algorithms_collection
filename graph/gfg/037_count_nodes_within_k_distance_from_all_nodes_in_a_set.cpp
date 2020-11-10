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
    assert(cost >= 0 or cost <= 0);
}

void dfs(Graph& graph, vb& visited, int k, int at) {
    if (k < 0) {
        return;
    }
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs(graph, visited, k - 1, adj);
        }
    }
}

int FindKDistance(Graph& graph, vi terminals, int k) {
    int n = graph.size();
    vb reachable(n, true);

    for (int terminal : terminals) {
        vb visited(n);
        dfs(graph, visited, k, terminal);
        for (int i = 0; i < n; ++i) {
            if (not visited[i]) {
                reachable[i] = false;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < n; ++i) {
        if (reachable[i]) {
            ++total;
            cout << i << ' ';
        }
    }
    cout << '\n';
    return total;
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
    //cout << FindKDistance2(graph, {1, 2, 4}, 3) << endl;
}
