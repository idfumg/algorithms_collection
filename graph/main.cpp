#include "../template.hpp"
#include "graph.hpp"
#include "tree_node.hpp"

void dfs(const Graph& graph, vb& visited, vi& disc, vi& low, int& id, int at, int root, int parent) {
    visited[at] = true;
    disc[at] = low[at] = id++;
    for (const auto& edge : graph.edges(at)) {
        if (edge.to == parent) {
            continue;
        }
        else if (not visited[edge.to]) {
            dfs(graph, visited, disc, low, id, edge.to, root, at);
            low[at] = min(low[at], low[edge.to]);

            if (disc[at] < low[edge.to] and at != root) {
                cout << edge.from << ' ' << edge.to << endl;
            }
        }
        else {
            low[at] = min(low[at], disc[edge.to]);
        }
    }
}

void Tarjan(const Graph& graph) {
    vb visited(graph.size());
    vi disc(graph.size()), low(graph.size());
    int id = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if (not visited[i]) {
            dfs(graph, visited, disc, low, id, i, i, -1);
        }
    }
}

void FindBridges(const Graph& graph) {
    Tarjan(graph);
    cout << endl;
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
