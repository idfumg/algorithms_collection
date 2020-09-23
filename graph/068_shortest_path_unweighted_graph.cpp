#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void PrintShortestDistance(Graph& graph, int from, int to) {
    int n = graph.size();
    vi prev(n, -1);
    vi dist(n, -1);
    qi q;
    dist[from] = 0;
    q.push(from);
    while (not q.empty()) {
        int at = q.front(); q. pop();
        if (at == to) break;
        for (int adj : graph[at]) {
            if (dist[adj] == -1) {
                dist[adj] = dist[at] + 1;
                prev[adj] = at;
                q.push(adj);
            }
        }
    }
    cout << "MinimumDistance is: " << dist[to] << endl;
    cout << "Path to the final vertex is: ";
    vi path;
    for (int at = to; at != -1; at = prev[at]) {
        path.push_back(at);
    }
    reverse(path);
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
    PrintShortestDistance(graph, 0, 7);
}
