#include "../../template.hpp"

using Graph = vvi;

void AddUndirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void AddDirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

bool DetectCycleFloydWarshall(Graph dp) {
    int n = dp.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (dp[i][i] < 0) {
            return true;
        }
    }
    return false;
}

int main() { TimeMeasure _;
    Graph graph = { {0   , 1   , INF , INF},
                  {INF , 0   , -1  , INF},
                  {INF , INF , 0   ,  -1},
                  {-1  , INF , INF ,   0} };
    cout << DetectCycleFloydWarshall(graph) << '\n';
}
