#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void dfs(Graph& graph, int at, vb& visited, vi& disc, vi& lows, int& id, vb& onstack, stack<int>& saved) {
    visited[at] = true;
    onstack[at] = true;
    saved.push(at);
    disc[at] = lows[at] = id++;
    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            dfs(graph, edge.to, visited, disc, lows, id, onstack, saved);
            // check if the next node can reach node behind the current one
            // so, we can reach from the current node the same node behind
            // thus, the current node is part of SCC but not the start of one
            lows[at] = min(lows[at], lows[edge.to]);
        }
        else if (onstack[edge.to]) {
            // we already was at that node
            // if we already constructed SCC by it we don't use it
            // if we at the process of constructing SCC by now we use it by
            // checking if that node lay on the stack
            // so we use it discovery value to form our SCC and update lows
            // for every previous node when backtracking to this lowest discovery
            // time
            lows[at] = min(lows[at], disc[edge.to]);
        }
    }
    if (lows[at] == disc[at]) {
        while (true) {
            int node = saved.top(); saved.pop();
            onstack[node] = false;
            cout << node << ' ';
            if (node == at) break;
        }
        cout << endl;
    }
}

void TarjanSCC(Graph& graph) {
    int n = graph.size();
    vb visited(n), onstack(n);
    vi disc(n), lows(n);
    stack<int> saved;
    int id = 0;
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            dfs(graph, i, visited, disc, lows, id, onstack, saved);
        }
    }
    cout << disc << endl;
    cout << lows << endl;
}

int main() { TimeMeasure _;
    {
        Graph graph(8);
        graph.addDirectedEdge(6, 0);
        graph.addDirectedEdge(6, 2);
        graph.addDirectedEdge(3, 4);
        graph.addDirectedEdge(6, 4);
        graph.addDirectedEdge(2, 0);
        graph.addDirectedEdge(0, 1);
        graph.addDirectedEdge(4, 5);
        graph.addDirectedEdge(5, 6);
        graph.addDirectedEdge(3, 7);
        graph.addDirectedEdge(7, 5);
        graph.addDirectedEdge(1, 2);
        graph.addDirectedEdge(7, 3);
        graph.addDirectedEdge(5, 0);
        TarjanSCC(graph);
    }
}

// 2 1 0
// 6 5 4
// 7 3
// 0 1 2 3 4 5 6 7
// 0 0 0 3 4 4 4 3
