#include "../../template.hpp"

using Graph = vvvi;
using Edges = vvi;

void AddEdge(Graph& graph, int from, int to, int weight) {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}

struct Node {
    int idx;
    int weight;
    bool operator<(const Node& rhs) const { return weight > rhs.weight; }
};

int Dijkstra(Graph& graph, int from, int to) {
    int n = graph.size();
    vi dist(n, INF);
    dist[from] = 0;
    vb visited(n);
    priority_queue<Node> pq;
    pq.push({from, dist[from]});
    while (not pq.empty()) {
        int at = pq.top().idx; pq.pop();
        visited[at] = true;
        for (vi& adj : graph[at]) {
            if (at == from and adj[0] == to) continue;
            if (at == to and adj[0] == from) continue;
            if (not visited[adj[0]]) {
                int cost = dist[at] + adj[1];
                if (cost < dist[adj[0]]) {
                    dist[adj[0]] = cost;
                    pq.push({adj[0], cost});
                }
            }
        }
    }
    return dist[to];
}

void FindMinCycle(Graph& graph) {
    int n = graph.size();
    int mincycle = INF;
    vb visited(n);
    for (int i = 0; i < n; ++i) {
        for (vi& adj : graph[i]) {
            if (visited[adj[0]]) continue;
            int cost = Dijkstra(graph, i, adj[0]) + adj[1];
            mincycle = min(mincycle, cost);
        }
        visited[i] = true;
    }
    cout << mincycle << '\n';
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
