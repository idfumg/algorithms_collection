#include "../template.hpp"

using Graph = vvi;

void AddUndirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void AddDirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

struct Node {
    int idx;
    int weight;
    bool operator<(const Node& rhs) const { return weight > rhs.weight; }
};

void TotalCost(Graph& graph) {
    int n = graph.size(), from = 0;
    priority_queue<Node> pq;
    vi dist(n, INF);
    vb visited(n);
    vi prev(n, -1);
    dist[from] = 0;
    pq.push({from, dist[from]});
    while (not pq.empty()) {
        int at = pq.top().idx; pq.pop();
        visited[at] = true;
        for (int adj = 0; adj < n; ++adj) {
            if (graph[at][adj] and not visited[adj]) {
                if (dist[adj] > graph[at][adj]) {
                    dist[adj] = graph[at][adj];
                    prev[adj] = at;
                    pq.push({adj, dist[adj]});
                }
            }
        }
    }
    int total = 0;
    for (int i = 1; i < n; ++i) {
        cout << prev[i] << '-' << i << ' ' << dist[i] << '\n';
        total += dist[i];
    }
    debugn(total);
}

int main() { TimeMeasure _;
    {
        Graph graph = {{0, 1, 2, 3, 4},
                       {1, 0, 5, 0, 7},
                       {2, 5, 0, 6, 0},
                       {3, 0, 6, 0, 0},
                       {4, 7, 0, 0, 0}};
        TotalCost(graph); // 10
    }
    {
        Graph graph = {{0, 1, 1, 100, 0, 0},
                       {1, 0, 1, 0, 0, 0},
                       {1, 1, 0, 0, 0, 0},
                       {100, 0, 0, 0, 2, 2},
                       {0, 0, 0, 2, 0, 2},
                       {0, 0, 0, 2, 2, 0}};
        TotalCost(graph); // 106
    }
}
