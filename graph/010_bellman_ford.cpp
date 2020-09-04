#include "../template.hpp"
#include "graph.hpp"
#include "tree_node.hpp"

void BellmanFord(const Graph& graph, int from) {
    vi dist(graph.size(), INF);
    dist[from] = 0;

    for (size_t i = 0; i < graph.size() - 1; ++i) {
        for (const auto& edges : graph) {
            for (const auto& edge : edges) {
                if (dist[edge.from] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = dist[edge.from] + edge.cost;
                }
            }
        }
    }

    cout << dist;

    for (size_t i = 0; i < graph.size() - 1; ++i) {
        for (const auto& edges : graph) {
            for (const auto& edge : edges) {
                if (dist[edge.from] + edge.cost < dist[edge.to]) {
                    dist[edge.to] = -INF;
                }
            }
        }
    }

    cout << dist;
}

int main() { TimeMeasure _;
    Graph graph(9);
    graph.addDirectedEdge(0, 1, 1);
    graph.addDirectedEdge(1, 2, 1);
    graph.addDirectedEdge(2, 4, 1);
    graph.addDirectedEdge(4, 3, -3);
    graph.addDirectedEdge(3, 2, 1);
    graph.addDirectedEdge(1, 5, 4);
    graph.addDirectedEdge(1, 6, 4);
    graph.addDirectedEdge(5, 6, 5);
    graph.addDirectedEdge(6, 7, 4);
    graph.addDirectedEdge(5, 7, 3);
    BellmanFord(graph, 0);
}


// Output:
// The cost to get from node 0 to 0 is 0.00
// The cost to get from node 0 to 1 is 1.00
// The cost to get from node 0 to 2 is -Infinity
// The cost to get from node 0 to 3 is -Infinity
// The cost to get from node 0 to 4 is -Infinity
// The cost to get from node 0 to 5 is 5.00
// The cost to get from node 0 to 6 is 5.00
// The cost to get from node 0 to 7 is 8.00
// The cost to get from node 0 to 8 is Infinity
