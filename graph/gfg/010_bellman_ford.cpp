#include "../../template.hpp"

void BellmanFord(vvi edges, int from, int n) {
    vi dist(n, INF);
    dist[from] = 0;
    for (int i = 0; i < n; ++i) {
        for (vi edge : edges) {
            dist[edge[1]] = min(dist[edge[1]], dist[edge[0]] + edge[2]);
        }
    }
    for (int i = 0; i < n; ++i) {
        for (vi edge : edges) {
            if (dist[edge[1]] > dist[edge[0]] + edge[2]) {
                dist[edge[1]] = -INF;
            }
        }
    }
    cout << dist << endl;
}

int main() { TimeMeasure _;
    vvi edges;
    edges.push_back({0, 1, 1});
    edges.push_back({1, 2, 1});
    edges.push_back({2, 4, 1});
    edges.push_back({4, 3, -3});
    edges.push_back({3, 2, 1});
    edges.push_back({1, 5, 4});
    edges.push_back({1, 6, 4});
    edges.push_back({5, 6, 5});
    edges.push_back({6, 7, 4});
    edges.push_back({5, 7, 3});
    BellmanFord(edges, 0, 8);
// Output:
// The cost to get from node 0 to 0 is 0.00
// The cost to get from node 0 to 1 is 1.00
// The cost to get from node 0 to 2 is -Infinity
// The cost to get from node 0 to 3 is -Infinity
// The cost to get from node 0 to 4 is -Infinity
// The cost to get from node 0 to 5 is 5.00
// The cost to get from node 0 to 6 is 5.00
// The cost to get from node 0 to 7 is 8.00
}
