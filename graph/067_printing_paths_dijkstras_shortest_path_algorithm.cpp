#include "../template.hpp"

using Graph = vvi;

struct Node {
    int idx;
    int weight;
    bool operator<(const Node& rhs) const { return weight > rhs.weight; }
};

void Dijkstra(Graph& graph, int from) {
    int n = graph.size();
    vb visited(n);
    vi dist(n, INF);
    dist[from] = 0;
    vi prev(n, -1);
    priority_queue<Node> pq;
    pq.push({from, dist[from]});
    while (not pq.empty()) {
        int at = pq.top().idx; pq.pop();
        visited[at] = true;
        for (int i = 0; i < n; ++i) {
            if (graph[at][i] and not visited[i]) {
                int cost = dist[at] + graph[at][i];
                if (cost < dist[i]) {
                    dist[i] = cost;
                    prev[i] = at;
                    pq.push({i, dist[i]});
                }
            }
        }
    }
    for (int i = 1; i < n; ++i) {
        vi path;
        for (int at = i; at != -1; at = prev[at]) {
            path.push_back(at);
        }
        reverse(path);
        cout << from << '-' << '>' << i << ' ' << '(' << dist[i] << ')' << ' ' << path << '\n';
    }
}

int main() { TimeMeasure _;
    Graph graph = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                   {4, 0, 8, 0, 0, 0, 0, 11, 0},
                   {0, 8, 0, 7, 0, 4, 0, 0, 2},
                   {0, 0, 7, 0, 9, 14, 0, 0, 0},
                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
                   {0, 0, 4, 0, 10, 0, 2, 0, 0},
                   {0, 0, 0, 14, 0, 2, 0, 1, 6},
                   {8, 11, 0, 0, 0, 0, 1, 0, 7},
                   {0, 0, 2, 0, 0, 0, 6, 7, 0}};
    Dijkstra(graph, 0);
}
