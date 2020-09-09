#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool bfs(Graph& graph, vb& visited, int from) {
    deque<int> q;
    q.push_back(from);
    vi color(size(graph));
    color[from] = 1;
    while (not q.empty()) {
        int node = q.front(); q.pop_front();
        visited[node] = true;
        for (const auto& edge : graph.edges(node)) {
            if (not visited[edge.to]) {
                color[edge.to] = 1 - color[node];
                q.push_back(edge.to);
            }
            else if (color[edge.to] == color[node]) {
                return false;
            }
        }
    }
    return true;
}

bool IsBipartite(Graph& graph) {
    int  n = size(graph);
    vb visited(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            if (not bfs(graph, visited, i)) {
                return false;
            }
        }
    }
    return true;
}

int main() { TimeMeasure _;
    vvi matrix = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0},
    };

    Graph graph(size(matrix));
    for (int i = 0; i < size(matrix); ++i) {
        for (int j = 0; j < size(matrix[0]); ++j) {
            if (matrix[i][j] == 1) {
                graph.addUndirectedEdge(i, j);
            }
        }
    }

    cout << IsBipartite(graph) << endl;
}
