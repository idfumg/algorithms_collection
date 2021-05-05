#include "../../template.hpp"

void dfs(Graph& graph, int at, vb& visited, vi& desc, vi& lows, int& id, vb& ap, int root, int parent, int& rootOutcomingEdges) {
    if (parent == root) {
        rootOutcomingEdges++;
    }
    visited[at] = true;
    desc[at] = lows[at] = id++;
    for (const auto& edge : graph.edges(at)) {
        if (edge.to == parent) {
            continue;
        }
        else if (not visited[edge.to]) {
            dfs(graph, edge.to, visited, desc, lows, id, ap, root, at, rootOutcomingEdges);
            lows[at] = min(lows[at], lows[edge.to]);
            if (desc[at] <= lows[edge.to] and at != root) {
                ap[at] = true;
            }
        }
        else {
            lows[at] = min(lows[at], desc[edge.to]);
        }
    }
}

void FindArticulationPoints(Graph& graph) {
    int n = graph.size(), id = 0;
    vb visited(n), ap(n);
    vi desc(n), lows(n);
    for (int at = 0; at < n; ++at) {
        if (not visited[at]) {
            int rootOutcomingEdges = 0;
            dfs(graph, at, visited, desc, lows, id, ap, at, -1, rootOutcomingEdges);
            if (rootOutcomingEdges > 1) {
                ap[at] = true;
            }
        }
    }
    cout << ap << endl;
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
        FindArticulationPoints(graph); // 0 0 1 1 0 1 0 0 0
    }
    {
        Graph graph(3);
        graph.addUndirectedEdge(0, 1);
        graph.addUndirectedEdge(1, 2);
        FindArticulationPoints(graph); // 0 1 0
    }
    {
        Graph graph(5);
        graph.addUndirectedEdge(1, 0);
        graph.addUndirectedEdge(0, 2);
        graph.addUndirectedEdge(2, 1);
        graph.addUndirectedEdge(0, 3);
        graph.addUndirectedEdge(3, 4);
        FindArticulationPoints(graph); // 1 0 0 1 0
    }
    {
        Graph graph(4);
        graph.addUndirectedEdge(0, 1);
        graph.addUndirectedEdge(1, 2);
        graph.addUndirectedEdge(2, 3);
        FindArticulationPoints(graph); // 0 1 1 0
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
        FindArticulationPoints(graph); // 0 1 0 0 0 0 0
    }
}
