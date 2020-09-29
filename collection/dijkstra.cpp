#include "../template.hpp"

struct Node {
    int idx;
    int weight;
    bool operator<(const Node& rhs) const { return weight > rhs.weight; }
};

ostream& operator<<(ostream& os, const Node& node) {
    return os << '{' << node.idx << ',' << node.weight << '}';
}

using Graph = vector<vector<Node>>;

void AddDirectedEdge(Graph& graph, int from, int to, int weight) {
    graph[from].push_back({to, weight});
}

void Dijkstra(Graph& graph, int from, int to) {
    int n = graph.size();
    priority_queue<Node> pq;
    vi dist(n, INF);
    dist[from] = 0;
    pq.push({from, dist[from]});
    vb visited(n);
    vi prev(n, -1);
    while (not pq.empty()) {
        int at = pq.top().idx; pq.pop();
        for (Node& adj : graph[at]) {
            if (not visited[adj.idx]) {
                int cost = dist[at] + adj.weight;
                if (dist[adj.idx] > cost) {
                    dist[adj.idx] = cost;
                    prev[adj.idx] = at;
                    pq.push({adj.idx, cost});
                }
            }
        }
    }
    cout << "distances: " << dist << '\n';
    vi path;
    for (int at = to; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path);
    cout << "path: " << path << '\n';
}

int main() { TimeMeasure _;
    Graph graph(7);
    AddDirectedEdge(graph, 0, 1, 3);
    AddDirectedEdge(graph, 0, 2, 2);
    AddDirectedEdge(graph, 0, 5, 3);
    AddDirectedEdge(graph, 1, 3, 1);
    AddDirectedEdge(graph, 1, 2, 6);
    AddDirectedEdge(graph, 2, 3, 1);
    AddDirectedEdge(graph, 2, 4, 10);
    AddDirectedEdge(graph, 3, 4, 5);
    AddDirectedEdge(graph, 5, 4, 7);
    Dijkstra(graph, 0, 4);

// 0 3 2 3 8 3 1000000000
// 0 2 3 4
}
