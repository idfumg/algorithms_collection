#include "../../template.hpp"

void dfs(vvb& graph, vb& visited, int len, int at, int& count, int root) {
    int n = graph.size();
    visited[at] = true;
    for (int i = 0; i < n; ++i) {
        if (graph[at][i]) {
            if (not visited[i]) {
                dfs(graph, visited, len - 1, i, count, at);
            }
            else if (i == root and len - 1 == 0) {
                ++count;
            }
        }
    }
}

void CountCycles(vvb& graph, int len) {
    int n = graph.size(), count = 0;
    for (int i = 0; i < n; ++i) {
        vb visited(n);
        dfs(graph, visited, len, i, count, i);
    }
    cout << count / 2 << endl;
}

int main() { TimeMeasure _;
    vvb graph = {{0, 1, 0, 1, 0},
                 {1, 0, 1, 0, 1},
                 {0, 1, 0, 1, 0},
                 {1, 0, 1, 0, 1},
                 {0, 1, 0, 1, 0}};
    CountCycles(graph, 4);
}
