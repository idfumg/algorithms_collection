#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
}

void dfs(Graph& graph, vb& visited, vb& onstack, vi& path, vi& disc, vi& lows, int at, int& id) {
    visited[at] = true;
    onstack[at] = true;
    path.push_back(at);
    disc[at] = lows[at] = id++;

    for (int adj : graph[at]) {
        if (not visited[adj]) {
            dfs(graph, visited, onstack, path, disc, lows, adj, id);
            // check if the next node can reach node behind the current one
            // so, we can reach from the current node the same node behind
            // thus, the current node is part of SCC but not the start of one
            lows[at] = min(lows[at], lows[adj]);
        }
        else if (onstack[adj]) {
            // we already was at that node
            // if we already constructed SCC by it we don't use it
            // if we at the process of constructing SCC by now we use it by
            // checking if that node lay on the stack
            // so we use it discovery value to form our SCC and update lows
            // for every previous node when backtracking to this lowest discovery
            // time
            lows[at] = min(lows[at], disc[adj]);
        }
    }
    if (lows[at] == disc[at]) {
        while (not path.empty()) {
            int node = path.back(); path.pop_back();
            onstack[node] = false;
            cout << node << ' ';
            if (node == at) break;
        }
        cout << '\n';
    }
}

void TarjanSCC(Graph& graph) {
    int n = graph.size();
    int id = 0;
    vi disc(n, -1);
    vi lows(n);
    vb onstack(n);
    vb visited(n);
    vi path;

    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            dfs(graph, visited, onstack, path, disc, lows, i, id);
        }
    }

    debugn(disc);
    debugn(lows);
}

int main() { TimeMeasure _;
    {
        Graph graph(8);
        AddEdge(graph, 6, 0);
        AddEdge(graph, 6, 2);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 6, 4);
        AddEdge(graph, 2, 0);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 4, 5);
        AddEdge(graph, 5, 6);
        AddEdge(graph, 3, 7);
        AddEdge(graph, 7, 5);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 7, 3);
        AddEdge(graph, 5, 0);
        TarjanSCC(graph);
    }
}

// 2 1 0
// 6 5 4
// 7 3
// 0 1 2 3 4 5 6 7
// 0 0 0 3 4 4 4 3
