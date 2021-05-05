#include "../../template.hpp"

using Graph = vvvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    // graph[from].push_back(to);
    // graph[to].push_back(from);
    // graph.push_back({from, to});
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

struct Item {
    int at;
    int cost;
    bool operator<(const Item& rhs) const { return cost > rhs.cost; }
};

void PrimsMinSpanningTree(vvvi graph) {
    int n = graph.size();

    priority_queue<Item> q;
    q.push({0, 0});

    vb visited(n);

    vi dist(n, INF);
    dist[0] = 0;

    vi prev(n, -1);

    while (not q.empty()) {
        Item item = q.top(); q.pop();
        int at = item.at;
        visited[at] = true;
        for (vi adj : graph[at]) {
            if (not visited[adj[0]] and adj[1] < dist[adj[0]]) {
                dist[adj[0]] = adj[1];
                prev[adj[0]] = at;
                q.push({adj[0], adj[1]});
            }
        }
    }
    int totalCost = 0;
    for (int at = 1; at < n; ++at) {
        cout << at << '-' << prev[at] << ' ' << dist[at] << endl;
        totalCost += dist[at];
    }
    debugn(totalCost);
}

int main() { TimeMeasure _;
    {
        int n = 9;
        Graph graph(n);
        AddEdge(graph, 0, 1, 4);
        AddEdge(graph, 0, 7, 8);
        AddEdge(graph, 1, 2, 8);
        AddEdge(graph, 1, 7, 11);
        AddEdge(graph, 7, 6, 1);
        AddEdge(graph, 7, 8, 7);
        AddEdge(graph, 8, 2, 2);
        AddEdge(graph, 6, 5, 2);
        AddEdge(graph, 2, 3, 7);
        AddEdge(graph, 2, 5, 4);
        AddEdge(graph, 5, 4, 10);
        AddEdge(graph, 3, 4, 9);
        PrimsMinSpanningTree(graph); // 37
    }
    {
        int n = 5;
        Graph graph(n);
        AddEdge(graph, 0, 1, 2);
        AddEdge(graph, 0, 3, 6);
        AddEdge(graph, 1, 0, 2);
        AddEdge(graph, 1, 2, 3);
        AddEdge(graph, 1, 3, 8);
        AddEdge(graph, 1, 4, 5);
        AddEdge(graph, 2, 1, 3);
        AddEdge(graph, 2, 4, 7);
        AddEdge(graph, 3, 0, 6);
        AddEdge(graph, 3, 1, 8);
        AddEdge(graph, 3, 4, 9);
        AddEdge(graph, 4, 1, 5);
        AddEdge(graph, 4, 2, 7);
        AddEdge(graph, 4, 3, 9);
        PrimsMinSpanningTree(graph); // 16
    }
}
