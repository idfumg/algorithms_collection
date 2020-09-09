#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

int bfs(Graph& graph, int root) {
    int n = size(graph), height = 0;
    vb visited(n);
    deque<int> q;
    q.push_back(root);
    vi dist(n, -1);
    dist[root] = 0;
    while (not q.empty()) {
        int node = q.front(); q.pop_front();
        visited[node] = true;
        for (const auto& edge : graph.edges(node)) {
            if (not visited[edge.to]) {
                dist[edge.to] = dist[node] + 1;
                height = max(height, dist[edge.to]);
                q.push_back(edge.to);
            }
        }
    }
    return height;
}

int FindHeight(vi& arr) {
    int n = size(arr), root = 0;
    Graph graph(n);
    for (int i = 0; i < n; ++i) {
        if (arr[i] != -1) {
            graph.addUndirectedEdge(i, arr[i]);
        }
        else {
            root = i;
        }
    }
    return bfs(graph, root);
}

int main() { TimeMeasure _;
    vi arr1 = {-1, 0, 0, 0, 3, 1, 1, 2};
    vi arr2 = {-1, 0, 1, 2, 3};
    cout << FindHeight(arr1) << endl;
    cout << FindHeight(arr2) << endl;
}
