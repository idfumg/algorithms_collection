#include "../template.hpp"

using Graph = vvi;

struct Node : public vi {
    using vi::vi;
    bool operator<(const Node& rhs) const { return (*this)[1] > rhs[1]; }
};

void Dijkstra(Graph& graph, int from) {
    int n = graph.size();
    priority_queue<Node> pq;
    vi dist(n, INF);
    vb visited(n);
    vi prev(n, -1);
    dist[from] = 0;
    pq.push({from, dist[from]});
    while (not pq.empty()) {
        int at = pq.top()[0]; pq.pop();
        visited[at] = true;
        for (int i = 0; i < n; ++i) {
            int cost = dist[at] + graph[at][i];
            if (graph[at][i] and cost < dist[i] and not visited[i]) {
                dist[i] = cost;
                prev[i] = at;
                pq.push({i, cost});
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (i == from) continue;
        vi path;
        for (int at = i; at != -1; at = prev[at]) {
            path.push_back(at);
        }
        reverse(path);
        cout << '[' << from << '-' << '>' << i << ']' << ' ' << path << '[' << dist[i] << ']' << '\n';
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
