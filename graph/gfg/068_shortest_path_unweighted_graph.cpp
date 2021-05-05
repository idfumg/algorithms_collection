#include "../../template.hpp"

using Graph = vvi;

[[maybe_unused]] void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    assert(cost != INF);
    graph[from].push_back(to);
    graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

void PrintShortestDistance(vvi graph, int from, int to) {
    int n = graph.size();

    deque<int> q;
    q.push_back(from);

    vi dist(n, INF);
    dist[from] = 0;

    vb visited(n);

    vi prev(n, -1);

    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        visited[at] = true;

        for (int adj : graph[at]) {
            if (not visited[adj] and dist[adj] > dist[at] + 1) {
                dist[adj] = min(dist[adj], dist[at] + 1);
                prev[adj] = at;
                q.push_back(adj);
            }
        }
    }
    cout << dist[to] << endl;
    deque<int> path;
    for (int at = to; at != -1; at = prev[at]) {
        path.push_front(at);
    }
    cout << path << endl;
}

int main() { TimeMeasure _;
    Graph graph(8);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 3);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 3, 4);
    AddEdge(graph, 3, 7);
    AddEdge(graph, 4, 5);
    AddEdge(graph, 4, 6);
    AddEdge(graph, 4, 7);
    AddEdge(graph, 5, 6);
    AddEdge(graph, 6, 7);
    PrintShortestDistance(graph, 0, 7); // 2 // 0 3 7
    PrintShortestDistance(graph, 2, 6); // 5 // 2 1 0 3 4 6
}
