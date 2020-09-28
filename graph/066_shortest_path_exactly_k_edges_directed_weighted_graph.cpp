#include "../template.hpp"

using Graph = vvi;

int dfs(Graph& graph, int at, int to, int k, vi& dist, vi& prev) {
    int n = graph.size();
    if (at == to and k == 0) {
        debug(dist);
        return 1;
    }
    if (k <= 0) return 0;
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (graph[at][i]) {
            if (dist[i] > dist[at] + graph[at][i]) {
                dist[i] = dist[at] + graph[at][i];
                prev[i] = at;
            }
            dfs(graph, i, to, k - 1, dist, prev);
        }
    }
    return count;
}

void ShortestPathWithLengthK(Graph& graph, int from, int to, int k) {
    int n = graph.size();
    vi dist(n, INF), prev(n, -1);
    dist[from] = 0;
    cout << dfs(graph, from, to, k, dist, prev) << endl;
}

void ShortestPathWithLengthKDP(Graph& graph, int from, int to, int K) {
    int n = graph.size();
    vvvi dp(n, vvi(n, vi(n, INF)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != INF) dp[1][i][j] = graph[i][j];
        }
    }
    for (int k = 2; k <= K; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int p = 0; p < n; ++p) {
                    if (p != i and p != j) {
                        dp[k][i][j] = min(dp[k][i][j], dp[k - 1][i][p] + graph[p][j]);
                    }
                }
            }
        }
    }
    cout << dp[K][from][to] << endl;
}

int main() { TimeMeasure _;
    Graph graph = { {0, 10, 3, 2},
                    {INF, 0, INF, 7},
                    {INF, INF, 0, 6},
                    {INF, INF, INF, 0}};
    ShortestPathWithLengthK(graph, 0, 3, 2);
    ShortestPathWithLengthKDP(graph, 0, 3, 2);
}
