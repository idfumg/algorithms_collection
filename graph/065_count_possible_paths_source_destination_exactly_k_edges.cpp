#include "../template.hpp"

using Graph = vvi;

void CountWalkWithKEdgesDP(Graph& graph, int from, int to, int K) {
    int n = graph.size();
    vvvi dp(n, vvi(n, vi(n, 0)));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (graph[i][j]) dp[1][i][j] = 1;
            if (i == j) dp[0][i][j] = 1;
        }
    }
    for (int k = 2; k <= K; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < n; ++j) {
                for (int p = 0; p < n; ++p) {
                    if (graph[i][p]) {
                        dp[k][i][j] += dp[k - 1][p][j];
                    }
                }
            }
        }
    }
    cout << dp[K][from][to] << endl;
}

void dfs(Graph& graph, vb& visited, int to, int& count, int k, int at) {
    int n = graph.size();
    if (k == 0 and at == to) {
        ++count;
        return;
    }
    if (k <= 0) {
        return;
    }
    for (int adj = 0; adj < n; ++adj) {
        if (graph[at][adj] and not visited[adj]) {
            visited[adj] = true;
            dfs(graph, visited, to, count, k - 1, adj);
            visited[adj] = false;
        }
    }
}

void CountWalkWithKEdges(Graph& graph, int from, int to, int k) {
    int count = 0, n = graph.size();
    vb visited(n);
    visited[from] = true;
    dfs(graph, visited, to, count, k, from);
    cout << count;
}

int main() { TimeMeasure _;
    Graph graph = { { 0, 1, 1, 1 },
                    { 0, 0, 0, 1 },
                    { 0, 0, 0, 1 },
                    { 0, 0, 0, 0 } };
    CountWalkWithKEdgesDP(graph, 0, 3, 2);
    CountWalkWithKEdges(graph, 0, 3, 2);
}
