#include "../../template.hpp"

int dfs(vvb graph, vb& visited, int root, int k, int parent, int at, vi& path, set<vi>& paths) {
    if (k == 0 and at == root) {
        paths.insert(path);
        return 1;
    }
    if (k <= 0) return 0;
    visited[at] = true;
    int n = graph.size();
    int count = 0;
    for (int adj = 0; adj < n; ++adj) {
        if (adj == parent) continue;
        if (graph[at][adj]) {
            if (adj == root or not visited[adj]) {
                path.push_back(adj);
                count += dfs(graph, visited, root, k - 1, at, adj, path, paths);
                path.pop_back();
            }
        }
    }
    visited[at] = false;
    return count;
}

void CountCycles(vvb graph, int k) {
    int n = graph.size();
    vb visited(n);
    int count = 0;
    set<vi> paths;
    for (int at = 0; at < n; ++at) {
        if (not visited[at]) {
            vi path = {at};
            count += dfs(graph, visited, at, k - 0, -1, at, path, paths);
        }
    }
    debugn(paths);
    debugn(count / 2);
}

int main() { TimeMeasure _;
    vvb graph = {{0, 1, 0, 1, 0},
                 {1, 0, 1, 0, 1},
                 {0, 1, 0, 1, 0},
                 {1, 0, 1, 0, 1},
                 {0, 1, 0, 1, 0}};
    CountCycles(graph, 4); // 12
}
