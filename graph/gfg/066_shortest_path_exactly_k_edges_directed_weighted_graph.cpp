#include "../../template.hpp"

using Graph = vvi;

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
                    if (p == i or p == j) continue;
                    dp[k][i][j] = min(dp[k][i][j], dp[k - 1][i][p] + dp[1][p][j]);
                }
            }
        }
    }
    cout << dp[K][from][to] << '\n';
}

void dfs(Graph& graph, vb& visited, int at, int to, int k, int& count, int& mini)
{
    if (k == 0 and at == to) {
        mini = min(mini, count);
        return;
    }
    if (k <= 0) {
        return;
    }
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        if (graph[at][i]) {
            if (not visited[i]) {
                visited[i] = true;
                count += graph[at][i];
                dfs(graph, visited, i, to, k - 1, count, mini);
                count -= graph[at][i];
                visited[i] = false;
            }
        }
    }
}

void ShortestPathWithLengthK(Graph& graph, int from, int to, int k) {
    int n = graph.size(), count = 0, mini = INF;
    vb visited(n);
    visited[from] = true;
    dfs(graph, visited, from, to, k, count, mini);
    cout << mini << '\n';
}

int main() { TimeMeasure _;
    Graph graph = { {0, 10, 3, 2},
                    {INF, 0, INF, 7},
                    {INF, INF, 0, 6},
                    {INF, INF, INF, 0}};
    ShortestPathWithLengthKDP(graph, 0, 3, 2); // 9
    ShortestPathWithLengthK(graph, 0, 3, 2); // 9
}
