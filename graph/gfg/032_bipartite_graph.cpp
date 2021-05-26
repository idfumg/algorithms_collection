#include "../../template.hpp"

using Graph = vvi;

void AddUndirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void AddDirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

bool IsBipartiteBFS(vvi graph) {
    int n = graph.size();
    deque<int> q;
    q.push_back(0);
    vb visited(n);
    vi color(n, -1);
    color[0] = 1;
    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        visited[at] = true;
        for (int adj = 0; adj < n; ++adj) {
            if (not graph[at][adj]) continue;
            if (color[adj] == color[at]) return false;
            if (color[adj] == -1) {
                color[adj] = 1 - color[at];
                q.push_back(adj);
            }
        }
    }
    return true;
}

bool dfs(vvi graph, vi& color, int at) {
    int n = graph.size();
    for (int adj = 0; adj < n; ++adj) {
        if (not graph[at][adj]) continue;
        if (color[at] == color[adj]) return false;
        if (color[adj] != -1) continue;
        color[adj] = 1 - color[at];
        if (not dfs(graph, color, adj)) {
            return false;
        }
    }
    return true;
}

bool IsBipartiteDFS(vvi graph) {
    int n = graph.size();
    vi color(n, -1);
    for (int at = 0; at < n; ++at) {
        if (color[at] == -1) {
            color[at] = 0;
            if (not dfs(graph, color, at)) {
                return false;
            }
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
