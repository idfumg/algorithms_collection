#include "../template.hpp"

using Graph = vvvi;

void AddEdge(Graph& graph, int from, int to, int weight) {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}

void FindAllShortestDistances(Graph& graph, int from) {
    int n = graph.size();
    vi dist(n, INF);
    dist[from] = 0;
    deque<int> q;
    q.push_back(from);
    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        for (vi& adj : graph[at]) {
            int cost = dist[at] + adj[1];
            if (dist[adj[0]] > cost) {
                dist[adj[0]] = cost;
                if (adj[1] == 1) q.push_back(adj[0]);
                else q.push_front(adj[0]);
            }
        }
    }
    debug(dist);
}

int main() { TimeMeasure _;
    Graph graph(9);
    AddEdge(graph, 0, 1, 0);
    AddEdge(graph, 0, 7, 1);
    AddEdge(graph, 1, 7, 1);
    AddEdge(graph, 1, 2, 1);
    AddEdge(graph, 2, 3, 0);
    AddEdge(graph, 2, 5, 0);
    AddEdge(graph, 2, 8, 1);
    AddEdge(graph, 3, 4, 1);
    AddEdge(graph, 3, 5, 1);
    AddEdge(graph, 4, 5, 1);
    AddEdge(graph, 5, 6, 1);
    AddEdge(graph, 6, 7, 1);
    AddEdge(graph, 7, 8, 1);
    FindAllShortestDistances(graph, 0); // 'dist': 0 0 1 1 2 1 2 1 2
}
