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

void CountWalkWithKEdgesDP(Graph& graph, int from, int to, int K) {
    int n = graph.size();
    vvvi dp(n, vvi(n, vi(K + 1, INF)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j]) {
                dp[i][j][1] = graph[i][j];
            }
        }
    }
    for (int k = 2; k <= K; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int p = 0; p < n; ++p) {
                    if (j == i or j == p) continue;
                    dp[i][p][k] = min(dp[i][p][k], dp[i][j][k - 1] + dp[j][p][1]);
                }
            }
        }
    }
    cout << dp[from][to][K] << endl;
}

void dfs(Graph& graph, vb& visited, int at, int to, int K, int& ans) {
    if (K == 0 and at == to) {
        ++ans;
        return;
    }
    if (K < 0) {
        return;
    }
    visited[at] = true;
    int n = graph.size();
    for (int adj = 0; adj < n; ++adj) {
        if (not visited[adj]) {
            dfs(graph, visited, adj, to, K - 1, ans);
        }
    }
    visited[at] = false;
}

void CountWalkWithKEdgesDFS(Graph& graph, int from, int to, int K) {
    int n = graph.size();
    vb visited(n);
    int ans = 0;
    dfs(graph, visited, from, to, K, ans);
    cout << ans << endl;
}

int main() { TimeMeasure _;
    Graph graph = { { 0, 1, 1, 1 },
                    { 0, 0, 0, 1 },
                    { 0, 0, 0, 1 },
                    { 0, 0, 0, 0 } };
    CountWalkWithKEdgesDP(graph, 0, 3, 2); // 2
    CountWalkWithKEdgesDFS(graph, 0, 3, 2); // 2
}
