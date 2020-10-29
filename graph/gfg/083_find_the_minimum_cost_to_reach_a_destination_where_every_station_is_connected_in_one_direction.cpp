#include "../../template.hpp"

using Graph = vvi;

int MinCost(Graph& graph) { // already topologically sorted so use it
    int n = graph.size();
    vi dist(n, INF);
    dist[0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            dist[j] = min(dist[j], dist[i] + graph[i][j]);
        }
    }
    return dist[n - 1];
}

int main() { TimeMeasure _;
    vvi graph = {{0, 15, 80, 90},
                 {INF, 0, 40, 50},
                 {INF, INF, 0, 70},
                 {INF, INF, INF, 0}};
    int n = graph.size();
    cout << "The Minimum cost to reach station " << n << " is " << MinCost(graph); // 65
}
