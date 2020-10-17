#include "../../template.hpp"

using Graph = vvvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    //graph[from].push_back(to);
    //graph[to].push_back(from);
    //graph.push_back({from, to});
    graph[from].push_back({to, cost});
}

struct Item {
    int at;
    int cost;
    bool operator<(const Item& rhs) const { return cost > rhs.cost; }
};

void Dijkstra(Graph& graph, int from, int to) {
    int n = graph.size();
    priority_queue<Item> pq;
    vi dist(n, INF);
    vb visited(n);
    vi prev(n, -1);

    dist[from] = 0;
    pq.push({from, dist[from]});

    while (not pq.empty()) {
        int at = pq.top().at; pq.pop();
        visited[at] = true;
        for (vi& adj : graph[at]) {
            if (not visited[adj[0]]) {
                int cost = dist[at] + adj[1];
                if (dist[adj[0]] > cost) {
                    dist[adj[0]] = cost;
                    prev[adj[0]] = at;
                    pq.push({adj[0], cost});
                }
            }
        }
    }

    cout << dist << '\n';
    deque<int> path;
    for (int at = to; at != -1; at = prev[at]) {
        path.push_front(at);
    }
    cout << path << '\n';
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
