#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

int MinNumberOfEdges(Graph& graph, int from, int to) {
    int n = graph.size();
    vb visited(n);
    qi q;
    vi dist(n, INF);
    dist[from] = 0;
    q.push(from);
    while (not q.empty()) {
        int at = q.front(); q.pop();
        visited[at] = true;
        for (int adj : graph[at]) {
            if (not visited[adj]) {
                dist[adj] = min(dist[adj], dist[at] + 1);
                q.push(adj);
            }
        }
    }
    return dist[to];
}

int main() { TimeMeasure _;
    Graph graph(9);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 7);
    AddEdge(graph, 1, 7);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 2, 5);
    AddEdge(graph, 2, 8);
    AddEdge(graph, 3, 4);
    AddEdge(graph, 3, 5);
    AddEdge(graph, 4, 5);
    AddEdge(graph, 5, 6);
    AddEdge(graph, 6, 7);
    AddEdge(graph, 7, 8);
    cout << MinNumberOfEdges(graph, 0, 5) << '\n'; // 3
}
