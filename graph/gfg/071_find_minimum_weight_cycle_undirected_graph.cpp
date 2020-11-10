#include "../../template.hpp"

using Graph = vvvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    // graph[from].push_back(to);
    // graph[to].push_back(from);
    // graph.push_back({from, to});
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

struct Item {
    int at;
    int cost;
    bool operator<(const Item& rhs) const { return cost > rhs.cost; }
};

struct Result {
    int cycleLength;
    int from;
    int to;
    si nodes;
    bool operator<(const Result& rhs) const {
        return nodes != rhs.nodes;
    }
};

Result Dijkstra(Graph& graph, int from, int to) {
    int n = graph.size();
    int edgeCost = 0;

    vi prev(n, -1);

    vi dist(n, INF);
    dist[from] = 0;

    priority_queue<Item> pq;
    pq.push({from, dist[from]});

    vb visited(n);

    while (not pq.empty()) {
        Item item = pq.top(); pq.pop();
        int at = item.at;

        visited[at] = true;

        for (vi adj : graph[at]) {
            if (at == from and adj[0] == to) {
                edgeCost = adj[1];
                continue;
            }
            if (adj[0] == from and at == to) {
                edgeCost = adj[1];
                continue;
            }
            if (not visited[adj[0]]) {
                int cost = dist[at] + adj[1];
                if (cost < dist[adj[0]]) {
                    dist[adj[0]] = cost;
                    prev[adj[0]] = at;
                    pq.push({adj[0], cost});
                }
            }
        }
    }
    si nodes;
    for (int at = to; at != -1; at = prev[at]) {
        nodes.insert(at);
    }
    return {
        dist[to] + edgeCost,
        from,
        to,
        nodes
    };
}

void FindMinCycle(Graph& graph) {
    int n = graph.size();
    int minCycleLength = INF;
    set<Result> results;
    for (int i = 0; i < n; ++i) {
        for (vi adj : graph[i]) {
            const auto result = Dijkstra(graph, i, adj[0]);
            if (minCycleLength > result.cycleLength) {
                minCycleLength = result.cycleLength;
                results.clear();
                results.insert(result);
            }
            if (minCycleLength == result.cycleLength) {
                results.insert(result);
            }
        }
    }
    for (const auto& result : results) {
        debug(result.cycleLength); debugn(result.nodes);
    }
}

int main() { TimeMeasure _;
    Graph graph(9);
    AddEdge(graph, 0, 1, 4);
    AddEdge(graph, 0, 7, 8);
    AddEdge(graph, 1, 2, 8);
    AddEdge(graph, 1, 7, 11);
    AddEdge(graph, 2, 3, 7);
    AddEdge(graph, 2, 8, 2);
    AddEdge(graph, 2, 5, 4);
    AddEdge(graph, 3, 4, 9);
    AddEdge(graph, 3, 5, 14);
    AddEdge(graph, 4, 5, 10);
    AddEdge(graph, 5, 6, 2);
    AddEdge(graph, 6, 7, 1);
    AddEdge(graph, 6, 8, 6);
    AddEdge(graph, 7, 8, 7);
    FindMinCycle(graph); // 14
}
