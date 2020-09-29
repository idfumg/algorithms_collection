#include "../template.hpp"

using Graph = vvi;

bool bfs(Graph& graph, vi& color, int from) {
    int n = graph.size();
    qi q;
    q.push(from);
    color[from] = 0;
    while (not q.empty()) {
        int at = q.front(); q.pop();
        for (int adj = 0; adj < n; ++adj) {
            if (not graph[at][adj]) {
                continue;
            }
            if (color[adj] == color[at]) {
                return false;
            }
            if (color[adj] == -1) {
                color[adj] = 1 - color[at];
                q.push(adj);
            }
        }
    }
    return true;
}

bool IsBipartiteBFS(Graph& graph) {
    int n = graph.size();
    vi color(n, -1);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1 and not bfs(graph, color, i)) return false;
    }
    return true;
}

bool dfs(Graph& graph, vi& color, int at) {
    int n = graph.size();
    for (int i = 0; i < n; ++i) {
        if (graph[at][i]) {
            if (color[i] == color[at]) {
                return false;
            }
            if (color[i] == -1) {
                color[i] = 1 - color[at];
                if (dfs(graph, color, i)) return true;
            }
        }
    }
    return true;
}

bool IsBipartiteDFS(Graph& graph) {
    int n = graph.size();
    vi color(n, -1);
    for (int i = 0; i < n; ++i) {
        color[i] = 0;
        if (color[i] == -1 and not dfs(graph, color, i)) {
            return false;
        }
    }
    return true;
}

int main() { TimeMeasure _;
    Graph graph = {{0, 1, 0, 1},
                 {1, 0, 1, 0},
                 {0, 1, 0, 1},
                 {1, 0, 1, 0}};
    cout << IsBipartiteBFS(graph) << '\n';
    cout << IsBipartiteDFS(graph) << '\n';
}
