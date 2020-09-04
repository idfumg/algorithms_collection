#include "../template.hpp"

int dfs(vvi& graph, int from, int to, int k) {
    if (k == 0 and from == to) return 1;
    if (k == 0) return 0;
    int count = 0;
    for (int i = 0; i < graph[from].size(); ++i) {
        if (graph[from][i] == 1) {
            count += dfs(graph, i, to, k - 1);
        }
    }
    return count;
}

int tab(vvi& graph, int from, int to, int K) {
    int V = graph.size();
    vvvi dp(K + 1, vvi(V, vi(V)));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (k == 0 and i == j) {
                    dp[k][i][j] = 1;
                }
                else if (k == 1 and graph[i][j] == 1) {
                    dp[k][i][j] = 1;
                }
                else if (k == 0) {
                    dp[k][i][j] = 0;
                }
                else {
                    for (int vertex = 0; vertex < graph[i].size(); ++vertex) {
                        if (graph[i][vertex] == 1) {
                            dp[k][i][j] += dp[k - 1][vertex][j];
                        }
                    }
                }
            }
        }
    }
    return dp[K][from][to];
}

int main() { TimeMeasure _; __x();
    vvi graph = { { 0, 1, 1, 1 },
                  { 0, 0, 0, 1 },
                  { 0, 0, 0, 1 },
                  { 0, 0, 0, 0 } };
    int u = 0, v = 3, k = 2;

    cout << dfs(graph, u, v, k) << endl;
    cout << tab(graph, u, v, k) << endl;
}
