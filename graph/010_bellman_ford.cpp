#include "../template.hpp"

using Graph = vvi;

void AddDirectedEdge(Graph& graph, int from, int to, int weight) {
    graph.push_back({from, to, weight});
}

void BellmanFord(Graph& graph, int from) {
    int n = graph.size();
    vi dist(n, INF);
    dist[from] = 0;
    for (int i = 0; i < n; ++i) {
        for (const auto& edge : graph) {
            dist[edge[1]] = min(dist[edge[1]], dist[edge[0]] + edge[2]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (const auto& edge : graph) {
            if (dist[edge[0]] + edge[2] < dist[edge[1]]) {
                dist[edge[1]] = -INF;
            }
        }
    }
    cout << dist << '\n';
}

int main() { TimeMeasure _;
    Graph graph;
    AddDirectedEdge(graph, 0, 1, 1);
    AddDirectedEdge(graph, 1, 2, 1);
    AddDirectedEdge(graph, 2, 4, 1);
    AddDirectedEdge(graph, 4, 3, -3);
    AddDirectedEdge(graph, 3, 2, 1);
    AddDirectedEdge(graph, 1, 5, 4);
    AddDirectedEdge(graph, 1, 6, 4);
    AddDirectedEdge(graph, 5, 6, 5);
    AddDirectedEdge(graph, 6, 7, 4);
    AddDirectedEdge(graph, 5, 7, 3);
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
