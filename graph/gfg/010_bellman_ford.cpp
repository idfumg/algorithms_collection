#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    // graph[from].push_back(to);
    // graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

void BellmanFord(Graph& graph, int from, int V) {
    vi dist(V, INF);
    dist[from] = 0;
    for (int i = 0; i < V; ++i) {
        for (const auto& edge : graph) {
            dist[edge[1]] = min(dist[edge[1]], dist[edge[0]] + edge[2]);
        }
    }
    debugn(dist);
    for (int i = 0; i < V; ++i) {
        for (const auto& edge : graph) {
            if (dist[edge[0]] + edge[2] < dist[edge[1]]) {
                dist[edge[1]] = -INF;
            }
        }
    }
    debugn(dist);
}

int main() { TimeMeasure _;
    Graph graph;
    AddEdge(graph, 0, 1, 1);
    AddEdge(graph, 1, 2, 1);
    AddEdge(graph, 2, 4, 1);
    AddEdge(graph, 4, 3, -3);
    AddEdge(graph, 3, 2, 1);
    AddEdge(graph, 1, 5, 4);
    AddEdge(graph, 1, 6, 4);
    AddEdge(graph, 5, 6, 5);
    AddEdge(graph, 6, 7, 4);
    AddEdge(graph, 5, 7, 3);
    BellmanFord(graph, 0, 8);
// Output:
// The cost to get from node 0 to 0 is 0.00
// The cost to get from node 0 to 1 is 1.00
// The cost to get from node 0 to 2 is -Infinity
// The cost to get from node 0 to 3 is -Infinity
// The cost to get from node 0 to 4 is -Infinity
// The cost to get from node 0 to 5 is 5.00
// The cost to get from node 0 to 6 is 5.00
// The cost to get from node 0 to 7 is 8.00
}
