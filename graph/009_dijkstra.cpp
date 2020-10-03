#include "../template.hpp"
#include "../collection/graph.hpp"

struct Node {
    int id;
    int value;
    bool operator<(const Node& other) const { return value > other.value; }
};

void Dijkstra(const Graph& graph, int from, int to) {
    vb visited(graph.size());

    vi dist(graph.size(), INF);
    dist[from] = 0;

    vi prev(graph.size(), -1);

    priority_queue<Node> pq;
    pq.push({from, dist[from]});

    while (not pq.empty()) {
        Node node = pq.top(); pq.pop();
        visited[node.id] = true;

        for (const auto& edge : graph.edges(node.id)) {
            if (not visited[edge.to]) {
                int cost = dist[edge.from] + edge.cost;
                if (cost < dist[edge.to]) {
                    dist[edge.to] = cost;
                    prev[edge.to] = node.id;
                    pq.push({edge.to, cost});
                }
            }
        }
    }

    cout << dist;

    vi path;
    for (int at = to; at != -1; at = prev[at]) path.push_back(at);
    reverse(path);
    cout << dist << endl;
    cout << path << endl;
    cout << dist[to] << endl;
}

int main() { TimeMeasure _;
    Graph graph(7);
    graph.addDirectedEdge(0, 1, 3);
    graph.addDirectedEdge(0, 2, 2);
    graph.addDirectedEdge(0, 5, 3);
    graph.addDirectedEdge(1, 3, 1);
    graph.addDirectedEdge(1, 2, 6);
    graph.addDirectedEdge(2, 3, 1);
    graph.addDirectedEdge(2, 4, 10);
    graph.addDirectedEdge(3, 4, 5);
    graph.addDirectedEdge(5, 4, 7);
    Dijkstra(graph, 0, 4);
}

// 0 3 2 3 8 3 1000000000
// 0 2 3 4
