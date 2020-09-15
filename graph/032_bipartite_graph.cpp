#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool bfs(vvi& graph, vi& colors, int from) {
    int n = size(graph);

    queue<int> q;
    q.push(from);

    while (not q.empty()) {
        int at = q.front(); q.pop();
        if (graph[at][at]) {
            return false;
        }
        for (int node = 0; node < n; ++node) {
            if (graph[at][node]) {
                if (colors[node] == -1) {
                    colors[node] = 1 - colors[at];
                    q.push(node);
                }
                else if (colors[node] == colors[at]) {
                    return false;
                }
            }
        }
    }

    return true;
}

bool IsBipartiteBFS(vvi& graph) {
    int n = size(graph);
    vi colors(n, -1);

    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) {
            if (not bfs(graph, colors, i)) {
                return false;
            }
        }
    }

    return true;
}

bool dfs(vvi& graph, vi& colors, int at, int prevcolor) {
    int n = size(graph);
    colors[at] = 1 - prevcolor;

    if (graph[at][at]) {
        return false;
    }

    for (int i = 0; i < n; ++i) {
        if (graph[at][i]) {
            if (colors[i] == -1) {
                if (not dfs(graph, colors, i, colors[at])) {
                    return false;
                }
            }
            else if (colors[i] == colors[at]) {
                return false;
            }
        }
    }

    return true;
}

bool IsBipartiteDFS(vvi& graph) {
    int n = size(graph);
    vi colors(n, -1);

    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) {
            if (not dfs(graph, colors, i, 1)) {
                return false;
            }
        }
    }

    return true;
}

int main() { TimeMeasure _;
    vvi graph = {{0, 1, 0, 1},
                 {1, 0, 1, 0},
                 {0, 1, 0, 1},
                 {1, 0, 1, 0}};
    cout << IsBipartiteBFS(graph) << endl;
    cout << IsBipartiteDFS(graph) << endl;
}
