#include "../template.hpp"

void AddEdge(vvvi& graph, int from, int to, int weight) {
    graph[to].push_back({from, weight});
}

void MinAvgWeightOfCycle(vvvi& edges) {
    int n = edges.size();

    vvi dp(n + 1, vi(n, INF)); // dp[i][j] - the shortest distance to reach j with exactly i edges
    dp[0][0] = 0;
    for (int k = 1; k <= n; ++k) { // k - exactly k edges to reach some chosen vertex
        for (int v = 0; v < n; ++v) { // choose some vertex
            for (vi& edge : edges[v]) { // to reach previous vertex
                if (dp[k - 1][edge[0]] != INF) {
                    dp[k][v] = min(dp[k][v], dp[k - 1][edge[0]] + edge[1]);
                }
            }
        }
    }
    debugn(dp);

    vd avg(n, -1);
    double minmean = INF;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (dp[n][i] != -1 and dp[j][i] != -1) {
                avg[i] = max(avg[i], (dp[n][i] - dp[j][i]) / (double)(n - j));
            }
        }
        if (avg[i] != -1) {
            minmean = min(minmean, avg[i]);
        }
    }
    debugn(minmean);
};

int main() { TimeMeasure _;
    {
        // vvi graph = {
        //     {0,   1,   10,  INF},
        //     {INF, 0,   3,   INF},
        //     {INF, INF, 0,   INF},
        //     {8,   0,   INF, 0},
        // };
        vvvi edges(4);
        AddEdge(edges, 0, 1, 1);
        AddEdge(edges, 0, 2, 10);
        AddEdge(edges, 1, 2, 3);
        AddEdge(edges, 2, 3, 2);
        AddEdge(edges, 3, 1, 0);
        AddEdge(edges, 3, 0, 8);
        MinAvgWeightOfCycle(edges);
    }
}
// a number of edges i / to reach a vertex j
// 0          1000000000 1000000000 1000000000
// 1000000000 1          10         1000000000
// 1000000000 1000000000 4          12
// 20         12         1000000000 6
// 14         6          15         1000000000
