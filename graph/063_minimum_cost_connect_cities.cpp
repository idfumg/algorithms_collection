#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

struct Node {
    int at;
    int weight;
    bool operator<(const Node& rhs) const { return weight > rhs.weight; }
};

void TotalCost(vvi& graph) {
    int n = graph.size();
    vb inmsp(n);
    vi parent(n, -1);
    vi key(n, INF);
    priority_queue<Node> pq;
    pq.push({0, 0});
    while (not pq.empty()) {
        Node node = pq.top(); pq.pop();
        inmsp[node.at] = true;
        for(int i = 0; i < n; ++i) {
            if (graph[node.at][i] and not inmsp[i] and key[i] > graph[node.at][i]) {
                parent[i] = node.at;
                key[i] = graph[node.at][i];
                pq.push(Node{i, key[i]});
            }
        }
    }
    int total = 0;
    for (int i = 1; i < n; ++i) {
        cout << parent[i] << '-' << i << ' ' << key[i] << '\n';
        total += key[i];
    }
    cout << '\n';
    debugn(total);
}

int main() { TimeMeasure _;
    {
        vvi graph = {{0, 1, 2, 3, 4},
                     {1, 0, 5, 0, 7},
                     {2, 5, 0, 6, 0},
                     {3, 0, 6, 0, 0},
                     {4, 7, 0, 0, 0}};
        TotalCost(graph); // 10
    }
    {
        vvi graph = {{0, 1, 1, 100, 0, 0},
                     {1, 0, 1, 0, 0, 0},
                     {1, 1, 0, 0, 0, 0},
                     {100, 0, 0, 0, 2, 2},
                     {0, 0, 0, 2, 0, 2},
                     {0, 0, 0, 2, 2, 0}};
        TotalCost(graph); // 106
    }
}
