#include "../../template.hpp"

using Graph = vvvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
}

struct Item {
    int at;
    int cost;
    bool operator<(const Item& rhs) const { return cost > rhs.cost; }
};

void dijkstra(vvvi graph, int from, int to, int& cost, deque<int>& path) {
    int n = graph.size();
    priority_queue<Item> pq;
    pq.push({from, 0});
    vi dist(n, INF);
    dist[from] = 0;
    vb visited(n);
    vi prev(n, -1);
    while (not pq.empty()) {
        Item item = pq.top(); pq.pop();
        int at = item.at;
        visited[at] = true;
        for (vi adj : graph[at]) {
            if (at == from and adj[0] == to) continue;
            if (at == to and adj[0] == from) continue;
            if (not visited[adj[0]]) {
                int cost = dist[at] + adj[1];
                if (cost < dist[adj[0]]) {
                    pq.push({adj[0], cost});
                    dist[adj[0]] = cost;
                    prev[adj[0]] = at;
                }
            }
        }
    }
    cost = dist[to];
    for (int at = to; at != -1; at = prev[at]) {
        path.push_front(at);
    }
}

void FindMinCycle(vvvi graph) {
    int n = graph.size();
    int cost = INF;
    deque<int> path;
    for (int at = 0; at < n; ++at) {
        for (vi adj : graph[at]) {
            int currcost = 0;
            deque<int> currpath;
            dijkstra(graph, at, adj[0], currcost, currpath);
            if (cost > currcost + adj[1]) {
                cost = currcost + adj[1];
                path = currpath;
            }
        }
    }
    cout << cost << endl;
    cout << path << endl;
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
