#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(Graph& graph, vi& disc, vi& lows, vi& parent, int& id, int at) {
    disc[at] = lows[at] = id++;
    for (int adj : graph[at]) {
        if (disc[adj] == -1) {
            parent[adj] = at;
            dfs(graph, disc, lows, parent, id, adj);
            lows[at] = min(lows[at], lows[adj]);
            if (disc[at] < lows[adj]) {
                cout << at << '-' << adj << ' ';
            }
        }
        else if (parent[at] != adj) {
            lows[at] = min(lows[at], disc[adj]);
        }
    }
}

void FindBridges(Graph& graph) {
    int n = graph.size(), id = 0;
    vi disc(n, -1), lows(n), parent(n, -1);
    for (int at = 0; at < n; ++at) {
        if (disc[at] == -1) {
            dfs(graph, disc, lows, parent, id, at);
            cout << '\n';
        }
    }
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
        FindBridges(graph); // 3-4 2-3 2-5
    }
    {
        Graph graph(3);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        FindBridges(graph); // 1-2 0-1
    }
    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        FindBridges(graph); // 3-4 0-3
    }
    {
        Graph graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        FindBridges(graph); // 2-3 1-2 0-1
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
        FindBridges(graph); // 1-6
    }
}
