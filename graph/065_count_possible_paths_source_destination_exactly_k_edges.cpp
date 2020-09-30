#include "../template.hpp"

using Graph = vvi;

void CountWalkWithKEdgesDP(Graph& graph, int from, int to, int K) {
    int n = graph.size();
    vvvi dp(K + 1, vvi(n, vi(n)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j]) dp[1][i][j] = 1;
            else if (i == j) dp[0][i][j] = 1;
        }
    }
    for (int k = 2; k <= K; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int p = 0; p < n; ++p) {
                    if (graph[p][j]) {
                        dp[k][i][j] += dp[k - 1][i][p];
                    }
                }
            }
        }
    }
    cout << dp[K][from][to] << '\n';
}

void dfs(Graph& graph, vb& visited, int at, int to, int k, int& count) {
    int n = graph.size();
    if (at == to and k == 0) {
        ++count;
        return;
    }
    if (k <= 0) {
        return;
    }
    for (int i = 0; i < n; ++i) {
        if (graph[at][i] and not visited[i]) {
            visited[i] = true;
            dfs(graph, visited, i, to, k - 1, count);
            visited[i] = false;
        }
    }

}

void CountWalkWithKEdgesDFS(Graph& graph, int from, int to, int K) {
    int n = graph.size(), count = 0;
    vb visited(n);
    dfs(graph, visited, from, to, K, count);
    cout << count << '\n';
}

int main() { TimeMeasure _;
    Graph graph = { { 0, 1, 1, 1 },
                    { 0, 0, 0, 1 },
                    { 0, 0, 0, 1 },
                    { 0, 0, 0, 0 } };
    CountWalkWithKEdgesDP(graph, 0, 3, 2); // 2
    CountWalkWithKEdgesDFS(graph, 0, 3, 2); // 2
}
