#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void dfs(Graph& graph, int at, vb& visited, vi& desc, vi& lows, int& id, int parent) {
    visited[at] = true;
    desc[at] = lows[at] = id++;
    for (const auto& edge : graph.edges(at)) {
        if (edge.to == parent) {
            continue;
        }
        else if (not visited[edge.to]) {
            dfs(graph, edge.to, visited, desc, lows, id, at);
            lows[at] = min(lows[at], lows[edge.to]);
            if (desc[at] < lows[edge.to] and at != parent) {
                cout << "Bridge: " << at << " -> " << edge.to << endl;
            }
        }
        else {
            lows[at] = min(lows[at], desc[edge.to]);
        }
    }
}

void FindBridges(Graph& graph) {
    int n = graph.size(), id = 0;
    vb visited(n);
    vi desc(n), lows(n);
    for (int at = 0; at < n; ++at) {
        if (not visited[at]) {
            dfs(graph, at, visited, desc, lows, id, at);
        }
    }
}

int main() { TimeMeasure _;
        {
        Graph graph(9);
        graph.addUndirectedEdge(0, 1);
        graph.addUndirectedEdge(0, 2);
        graph.addUndirectedEdge(1, 2);
        graph.addUndirectedEdge(2, 3);
        graph.addUndirectedEdge(3, 4);
        graph.addUndirectedEdge(2, 5);
        graph.addUndirectedEdge(5, 6);
        graph.addUndirectedEdge(6, 7);
        graph.addUndirectedEdge(7, 8);
        graph.addUndirectedEdge(8, 5);
        FindBridges(graph);
        // 3 4
// 2 3
// 2 5
    }
    {
        Graph graph(3);
        graph.addUndirectedEdge(0, 1);
        graph.addUndirectedEdge(1, 2);
        FindBridges(graph);
        // 1 2
    }
    {
        Graph graph(5);
        graph.addUndirectedEdge(1, 0);
        graph.addUndirectedEdge(0, 2);
        graph.addUndirectedEdge(2, 1);
        graph.addUndirectedEdge(0, 3);
        graph.addUndirectedEdge(3, 4);
        FindBridges(graph);
        // 3 4
    }
    {
        Graph graph(4);
        graph.addUndirectedEdge(0, 1);
        graph.addUndirectedEdge(1, 2);
        graph.addUndirectedEdge(2, 3);
        FindBridges(graph);
        // 2 3
        // 1 2
    }
    {
        Graph graph(7);
        graph.addUndirectedEdge(0, 1);
        graph.addUndirectedEdge(1, 2);
        graph.addUndirectedEdge(2, 0);
        graph.addUndirectedEdge(1, 3);
        graph.addUndirectedEdge(1, 4);
        graph.addUndirectedEdge(1, 6);
        graph.addUndirectedEdge(3, 5);
        graph.addUndirectedEdge(4, 5);
        FindBridges(graph);
        // 1 6
    }
}
