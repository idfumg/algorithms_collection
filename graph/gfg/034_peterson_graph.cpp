#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool dfs(Graph& graph, vb& visited, vi& path, const string& s, int at, int i) {
    if (i == s.size()) return true;
    if (s[i] - 'A' != at and s[i] - 'A' + 5 != at) return false;
    path.push_back(at);
    visited[at] = true;
    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            if (dfs(graph, visited, path, s, edge.to, i + 1)) return true;
        }
    }
    return false;
}

vi FindPath_(Graph& graph, const string& s) {
    int n = size(graph);
    vi path;
    vb visited(n);
    if (dfs(graph, visited, path, s, s[0] - 'A', 0)) return path;
    visited = vb(n);
    if (dfs(graph, visited, path, s, s[0] - 'A' + 5, 0)) return path;
    return {};
}

void FindPath(Graph& graph, const string& s) {
    const auto path = FindPath_(graph, s);
    if (path.empty()) cout << -1 << endl;
    else cout << path << endl;
}

int main() { TimeMeasure _;
    Graph graph(10);
    graph.addUndirectedEdge(0, 1);
    graph.addUndirectedEdge(0, 4);
    graph.addUndirectedEdge(1, 2);
    graph.addUndirectedEdge(1, 6);
    graph.addUndirectedEdge(2, 3);
    graph.addUndirectedEdge(2, 7);
    graph.addUndirectedEdge(3, 4);
    graph.addUndirectedEdge(3, 8);
    graph.addUndirectedEdge(4, 9);
    graph.addUndirectedEdge(5, 8);
    graph.addUndirectedEdge(5, 7);
    graph.addUndirectedEdge(6, 8);
    graph.addUndirectedEdge(6, 9);
    graph.addUndirectedEdge(7, 9);

    FindPath(graph, "ABB");
    FindPath(graph, "AABE");
}
