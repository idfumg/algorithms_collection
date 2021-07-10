#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(vvi graph, vi& lows, vi& disc, vi& parent, vi& ap, int& idx, int at) {
    lows[at] = disc[at] = idx++;
    int kids = 0;
    for (int adj : graph[at]) {
        if (lows[adj] == -1) {
            ++kids;
            parent[adj] = at;
            dfs(graph, lows, disc, parent, ap, idx, adj);
            lows[at] = min(lows[at], lows[adj]);
            if (parent[at] == -1 and kids > 1) ap[at] = 1;
            if (parent[at] != -1 and disc[at] <= lows[adj]) ap[at] = 1;
        }
        else if (parent[at] != adj) {
            lows[at] = min(lows[at], disc[adj]);
        }
    }
}

void FindArticulationPoints(vvi graph) {
    int n = graph.size(), idx = 0;
    vi lows(n, -1), disc(n), parent(n, -1), ap(n);
    for (int at = 0; at < n; ++at) {
        if (lows[at] == -1) {
            dfs(graph, lows, disc, parent, ap, idx, at);
        }
    }
    debugn(ap);
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
        FindArticulationPoints(graph); // 0 0 1 1 0 1 0 0 0
    }
    {
        Graph graph(3);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        FindArticulationPoints(graph); // 0 1 0
    }
    {
        Graph graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        FindArticulationPoints(graph); // 1 0 0 1 0
    }
    {
        Graph graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        FindArticulationPoints(graph); // 0 1 1 0
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
        FindArticulationPoints(graph); // 0 1 0 0 0 0 0
    }
}
