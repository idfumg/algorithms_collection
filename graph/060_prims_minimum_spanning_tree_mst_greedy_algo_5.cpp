#include "../template.hpp"

struct Node {
    int at;
    int weight;
    bool operator<(const Node& rhs) const { return weight > rhs.weight; }
};

using Graph = vector<vector<Node>>;

void AddEdge(Graph& graph, int from, int to, int weight) {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}

void PrimsMinSpanningTree(Graph& graph) {
    int n = graph.size();
    priority_queue<Node> pq;
    vb intree(n);
    vi dist(n, INF);
    vi prev(n, -1);

    pq.push({0, 0});
    while (not pq.empty()) {
        Node node = pq.top(); pq.pop();
        intree[node.at] = true;
        for (Node& adj : graph[node.at]) {
            if (not intree[adj.at] and dist[adj.at] > adj.weight) {
                pq.push(adj);
                dist[adj.at] = adj.weight;
                prev[adj.at] = node.at;
            }
        }
    }
    int total = 0;
    for (int i = 1; i < n; ++i) {
        cout << i << '-' << prev[i] << ' ' << dist[i] << '\n';
        total += dist[i];
    }
    debugn(total);
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
