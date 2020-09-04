#include "../template.hpp"
#include "graph.hpp"
#include "tree_node.hpp"

void dfs(const Graph& graph, vb& visited, vb& onstack, stack<int>& saved, vi& lows, vi& ids, int& id, int at) {
    visited[at] = true;
    saved.push(at);
    onstack[at] = true;
    lows[at] = ids[at] = id++;

    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            dfs(graph, visited, onstack, saved, lows, ids, id, edge.to);
            // which min id node we can reach from the subtree rooted at edge.to?
            lows[at] = min(lows[at], lows[edge.to]);
        }
        // without a cross edge because it violates SCC definition
        else if (onstack[edge.to]) {
            //take as a part of SCC of an edge.to
            lows[at] = min(lows[at], ids[edge.to]);
        }
    }

    if (ids[at] == lows[at]) {
        while (true) {
            int node = saved.top(); saved.pop();
            cout << node << ' ';
            onstack[node] = false;
            if (node == at) break;
        }
        cout << endl;
    }
}

void TarjanSCC(const Graph& graph) {
    vb visited(graph.size()), onstack(graph.size());
    vi lows(graph.size()), ids(graph.size());
    int id = 0;
    stack<int> saved;
    for (int at = 0; at < graph.size(); ++at) {
        if (not visited[at]) {
            dfs(graph, visited, onstack, saved, lows, ids, id, at);
        }
    }
    cout << ids;
    cout << lows;
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

// 0 1 2 3 4 5 6 7
// 0 0 0 3 4 4 4 3
