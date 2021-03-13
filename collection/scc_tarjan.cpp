#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

void dfs(Graph graph, vi& disc, vi& lows, vi& parent, vi& onpath, vi& path, int& idx, int at) {
    onpath[at] = disc[at] = lows[at] = idx++;
    path.push_back(at);
    for (int adj : graph[at]) {
        if (disc[adj] == -1) {
            // check if the next node can reach node behind the current one
            // so, we can reach from the current node the same node behind
            // thus, the current node is part of SCC but not the start of one
            dfs(graph, disc, lows, parent, onpath, path, idx, adj);
            lows[at] = min(lows[at], lows[adj]);
        }
        else if (onpath[adj]) {
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

    if (disc[at] == lows[at]) {
        while (not path.empty()) {
            int node = path.back(); path.pop_back();
            onpath[node] = 0;
            cout << node << ' ';
            if (node == at) break;
        }
        cout << endl;
    }
}

void PrintSCCs(Graph& graph) {
    int n = graph.size(), idx = 1;
    vi disc(n, -1), lows(n, 0), parent(n, -1), onpath(n, 0), path;
    for (int at = 0; at < n; ++at) {
        if (disc[at] == -1) {
            dfs(graph, disc, lows, parent, onpath, path, idx, at);
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
        PrintSCCs(graph);
    }
// 2 1 0
// 6 5 4
// 7 3
// 'disc': 0 1 2 3 4 5 6 7
// 'lows': 0 0 0 3 4 4 4 3
}
