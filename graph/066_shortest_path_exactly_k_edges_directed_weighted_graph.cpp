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

int main() { TimeMeasure _;
    Graph graph = { {0, 10, 3, 2},
                    {INF, 0, INF, 7},
                    {INF, INF, 0, 6},
                    {INF, INF, INF, 0}};
    ShortestPathWithLengthK(graph, 0, 3, 2);
}
