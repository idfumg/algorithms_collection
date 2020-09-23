#include "../template.hpp"

struct Node : public vi {
    using vi::vi;
    bool operator<(const Node& rhs) const { return (*this)[1] > rhs[1]; }
};

using Graph = vector<vector<Node>>;

void AddEdge(Graph& graph, int from, int to, int weight) {
    graph[from].push_back({to, weight});
    //graph[to].push_back({from, weight});
}

void Dijkstra(Graph& graph, int from, int to) {
    int n = graph.size();
    vb visited(n);
    vi prev(n, -1);

    vi dist(n, INF);
    dist[from] = 0;

    priority_queue<Node> pq;
    pq.push({from, dist[from]});

    while (not pq.empty()) {
        Node at = pq.top(); pq.pop();
        visited[at[0]] = true;

        for (Node& adj : graph[at[0]]) {
            if (not visited[adj[0]]) {
                int cost = dist[at[0]] + adj[1];
                if (cost < dist[adj[0]]) {
                    dist[adj[0]] = cost;
                    prev[adj[0]] = at[0];
                    pq.push({adj[0], cost});
                }
            }
        }
    }

    debugn(dist);

    vi path;
    for (int at = to; at != -1; at = prev[at]) path.push_back(at);
    reverse(path);
    debugn(path);
}

int main() { TimeMeasure _;
    Graph graph(7);
    AddEdge(graph, 0, 1, 3);
    AddEdge(graph, 0, 2, 2);
    AddEdge(graph, 0, 5, 3);
    AddEdge(graph, 1, 3, 1);
    AddEdge(graph, 1, 2, 6);
    AddEdge(graph, 2, 3, 1);
    AddEdge(graph, 2, 4, 10);
    AddEdge(graph, 3, 4, 5);
    AddEdge(graph, 5, 4, 7);
    Dijkstra(graph, 0, 4);
}

// 0 3 2 3 8 3 1000000000
// 0 2 3 4
