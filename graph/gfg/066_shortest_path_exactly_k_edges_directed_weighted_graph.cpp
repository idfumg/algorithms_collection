#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    // graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

void ShortestPathWithLengthKDP(Graph& graph, int from, int to, int K) {
    int n = graph.size();
    vvvi dp(n, vvi(n, vi(K + 1, INF)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j] != INF) {
                dp[i][j][1] = graph[i][j];
            }
        }
    }
    for (int k = 2; k <= K; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int l = 0; l < n; ++l) {
                    if (j == i or j == l) continue;
                    dp[i][l][k] = min(dp[i][l][k], dp[i][j][k - 1] + dp[j][l][1]);
                }
            }
        }
    }
    cout << dp[from][to][K] << endl;
}

void dfs(Graph& graph, vb& visited, int at, int to, int K, int& ans, int current) {
    if (K == 0 and at == to) ans = min(ans, current);
    if (K <= 0) return;
    visited[at] = true;
    int n = graph.size();
    for (int adj = 0; adj < n; ++adj) {
        if (not visited[adj] and graph[at][adj] != INF) {
            dfs(graph, visited, adj, to, K - 1, ans, current + graph[at][adj]);

        }
    }
    visited[at] = false;
}

void ShortestPathWithLengthK(Graph& graph, int from, int to, int K) {
    int n = graph.size();
    int ans = INF;
    vb visited(n);
    dfs(graph, visited, from, to, K, ans, 0);
    cout << ans << endl;
}

int main() { TimeMeasure _;
    Graph graph = { {0, 10, 3, 2},
                    {INF, 0, INF, 7},
                    {INF, INF, 0, 6},
                    {INF, INF, INF, 0}};
    ShortestPathWithLengthKDP(graph, 0, 3, 2); // 9
    ShortestPathWithLengthK(graph, 0, 3, 2); // 9
}
