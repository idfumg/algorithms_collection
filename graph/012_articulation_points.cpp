#include "../template.hpp"
#include "graph.hpp"
#include "tree_node.hpp"

void dfs(Graph& graph, vb& visited, int at, vi& low, vi& disc, int& id, int root, int parent, int& rootNodeOutcomingEdges, vb& apPoint) {
    if (root == parent) {
        rootNodeOutcomingEdges++;
    }
    visited[at] = true;
    low[at] = disc[at] = id++;

    for (const auto& edge : graph.edges(at)) {
        if (edge.to == parent) {
            continue;
        }
        else if (not visited[edge.to]) {
            dfs(graph, visited, edge.to, low, disc, id, root, at, rootNodeOutcomingEdges, apPoint);
            low[at] = min(low[at], low[edge.to]);

            if (disc[at] <= low[edge.to] and at != root) {
                apPoint[at] = true;
            }
        }
        else {
            low[at] = min(low[at], disc[edge.to]);
        }
    }
}

void FindArticulationPoints(Graph& graph) {
    vb visited(graph.size()), apPoint(graph.size());
    vi low(graph.size()), disc(graph.size());
    int id = 0;

    for (int at = 0; at < graph.size(); ++at) {
        if (not visited[at]) {
            int rootNodeOutcomingEdges = 0;
            dfs(graph, visited, at, low, disc, id, at, -1, rootNodeOutcomingEdges, apPoint);
            if (rootNodeOutcomingEdges > 1) {
                apPoint[at] = true;
            }
        }
    }

    cout << apPoint;
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
