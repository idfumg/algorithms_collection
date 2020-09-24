#include "../template.hpp"

using Edge = vi;
using Graph = vector<vector<Edge>>;
using Edges = vector<Edge>;

struct Node {
    int at;
    int weight;
    bool operator<(const Node& rhs) const { return weight > rhs.weight; }
};

void AddEdge(Graph& graph, Edges& edges, int from, int to, int weight) {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
    edges.push_back({from, to, weight});
}

int Dijkstra(Graph& graph, int from, int to) {
    int n = graph.size();
    vi dist(n, INF);
    dist[from] = 0;
    priority_queue<Node> pq;
    vb visited(n);
    pq.push({from, dist[from]});
    while (not pq.empty()) {
        int at = pq.top().at; pq.pop();
        visited[at] = true;
        for (Edge& adj : graph[at]) {
            if (at == from and adj[0] == to) continue;
            if (at == to and adj[0] == from) continue;
            int cost = dist[at] + adj[1];
            if (not visited[adj[0]] and cost < dist[adj[0]]) {
                dist[adj[0]] = cost;
                pq.push({adj[0], cost});
            }
        }
    }
    return dist[to];
}

void FindMinCycle(Graph& graph, Edges& edges) {
    int mincycle = INF;
    for (Edge& edge : edges) {
        int dist = Dijkstra(graph, edge[0], edge[1]) + edge[2];
        mincycle = min(mincycle, dist);
    }
    debug(mincycle);
}

int main() { TimeMeasure _;
    Graph graph(9);
    Edges edges;
    AddEdge(graph, edges, 0, 1, 4);
    AddEdge(graph, edges, 0, 7, 8);
    AddEdge(graph, edges, 1, 2, 8);
    AddEdge(graph, edges, 1, 7, 11);
    AddEdge(graph, edges, 2, 3, 7);
    AddEdge(graph, edges, 2, 8, 2);
    AddEdge(graph, edges, 2, 5, 4);
    AddEdge(graph, edges, 3, 4, 9);
    AddEdge(graph, edges, 3, 5, 14);
    AddEdge(graph, edges, 4, 5, 10);
    AddEdge(graph, edges, 5, 6, 2);
    AddEdge(graph, edges, 6, 7, 1);
    AddEdge(graph, edges, 6, 8, 6);
    AddEdge(graph, edges, 7, 8, 7);
    FindMinCycle(graph, edges);
}
