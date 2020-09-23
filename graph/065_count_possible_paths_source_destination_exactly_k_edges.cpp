#include "../template.hpp"

using Graph = vvi;

int dfs(Graph& graph, int at, int to, int k) {
    int n = graph.size();
    if (at == to and k == 0) return 1;
    if (k <= 0) return 0;

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (graph[at][i]) {
            count += dfs(graph, i, to, k - 1);
        }
    }
    return count;
}

void CountWalkWithKEdges(Graph& graph, int from, int to, int k) {
    int n = graph.size();
    cout << dfs(graph, from, to, k) << endl;
}

int main() { TimeMeasure _;
    Graph graph = { { 0, 1, 1, 1 },
                    { 0, 0, 0, 1 },
                    { 0, 0, 0, 1 },
                    { 0, 0, 0, 0 } };
    CountWalkWithKEdges(graph, 0, 3, 2);
}
