#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void dfs(Graph& graph, int i, vb& visited, vi& desc, vi& lows, int& id, vb& onstack, stack<int>& s, int parent) {
    visited[i] = true;
    onstack[i] = true;
    s.push(i);
    lows[i] = desc[i] = id++;
    for (const auto& edge : graph.edges(i)) {
        if (not visited[edge.to]) {
            dfs(graph, edge.to, visited, desc, lows, id, onstack, s, i);
            lows[i] = min(lows[i], lows[edge.to]);
        }
        else if (onstack[edge.to]) {
            lows[i] = min(lows[i], desc[edge.to]);
        }
        if (parent == edge.to) { // when there is a loop between two elements
            lows[i] = lows[parent];
        }
    }
    if (lows[i] == desc[i]) {
        while (true and not s.empty()) {
            int node = s.top(); s.pop();
            onstack[node] = false;
            if (node == i) break;
        }
    }
}

bool Tarjan(Graph& graph) {
    int n = graph.size(), id = 0;
    vb visited(n), onstack(n);
    vi desc(n), lows(n);
    stack<int> s;
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            dfs(graph, i, visited, desc, lows, id, onstack, s, -1);
        }
    }
    cout << desc << endl;
    cout << lows << endl;
    for (int i = 0; i < n; ++i) {
        if (lows[i] != 0) return false;
    }
    return true;
}

bool IsStronglyConnected(Graph& graph) {
    return Tarjan(graph);
}

int main() { TimeMeasure _;
    Graph g1(5);
    g1.addDirectedEdge(0, 1);
    g1.addDirectedEdge(1, 2);
    g1.addDirectedEdge(2, 3);
    g1.addDirectedEdge(3, 0);
    g1.addDirectedEdge(2, 4);
    g1.addDirectedEdge(4, 2);
    cout << IsStronglyConnected(g1) << endl;

    Graph g2(4);
    g2.addDirectedEdge(0, 1);
    g2.addDirectedEdge(1, 2);
    g2.addDirectedEdge(2, 3);
    cout << IsStronglyConnected(g2) << endl;
}
