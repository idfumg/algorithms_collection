#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(Graph& graph, vb& visited, vi& desc, vi& lows, int& id, int at, int parent) {
    visited[at] = true;
    desc[at] = lows[at] = id++;
    for (int adj : graph[at]) {
        if (adj == parent) {
            continue;
        }
        else if (not visited[adj]) {
            dfs(graph, visited, desc, lows, id, adj, at);
            lows[at] = min(lows[at], lows[adj]);
            if (desc[at] < lows[adj] and at != parent) {
                cout << at << ' ' << adj << '\n';
            }
        }
        else {
            lows[at] = min(lows[at], desc[adj]);
        }
    }
}

void FindBridges(Graph& graph) {
    int n = graph.size(), id = 0;
    vb visited(n);
    vi desc(n), lows(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            dfs(graph, visited, desc, lows, id, i, -1);
        }
    }
    cout << '\n';
}

int main() { TimeMeasure _;
    {
        Graph graph(9);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 2, 5);
        AddEdge(graph, 5, 6);
        AddEdge(graph, 6, 7);
        AddEdge(graph, 7, 8);
        AddEdge(graph, 8, 5);
        FindBridges(graph);
        // 3 4
// 2 3
// 2 5
    }
    {
        Graph graph(3);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        FindBridges(graph);
        // 1 2
    }
    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        FindBridges(graph);
        // 3 4
    }
    {
        Graph graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        FindBridges(graph);
        // 2 3
        // 1 2
    }
    {
        Graph graph(7);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 0);
        AddEdge(graph, 1, 3);
        AddEdge(graph, 1, 4);
        AddEdge(graph, 1, 6);
        AddEdge(graph, 3, 5);
        AddEdge(graph, 4, 5);
        FindBridges(graph);
        // 1 6
    }
}
