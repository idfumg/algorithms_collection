#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

struct Node {
    int at;
    int weight;
    bool operator<(const Node& other) const { return weight > other.weight; }
};

void AddEdge(vector<vector<Node>>& graph, const int from, const int to, const int weight) {
    graph[from].push_back({to, weight});
    graph[to].push_back({from, weight});
}

void PrimsMinSpanningTree(const vector<vector<Node>>& graph, const int n) {
    vi parent(n, -1);
    vi key(n, INF);
    vb intree(n);
    priority_queue<Node> pq;

    key[0] = 0;
    pq.push({0, 0});

    while (not pq.empty()) {
        Node node = pq.top(); pq.pop();
        intree[node.at] = true;
        for (const Node& adj : graph[node.at]) {
            if (not intree[adj.at] and key[adj.at] > adj.weight) {
                key[adj.at] = adj.weight;
                parent[adj.at] = node.at;
                pq.push(adj);
            }
        }
    }

    int total = 0;
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << '-' << i << ' ' << key[i] << '\n';
        total += key[i];
    }
    debugn(total);
}

int main() { TimeMeasure _;
    {
        int n = 9;
        vector<vector<Node>> graph(9);
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
        PrimsMinSpanningTree(graph, n);
    }
    {
        int n = 5;
        vector<vector<Node>> graph(5);
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
        PrimsMinSpanningTree(graph, n);
    }
}
