#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void dfs(Graph& graph, int from) {
    int n = graph.size();
    stack<int> s;
    s.push(from);
    vb visited(n);
    while (not s.empty()) {
        int node = s.top(); s.pop();
        if (not visited[node]) {
            visited[node] = true;
            cout << node << " ";
        }
        for (const auto& edge : graph.edges(node)) {
            if (not visited[edge.to]) {
                s.push(edge.to);
            }
        }
    }
}

int main() { TimeMeasure _;
    Graph g(5); // Total 5 vertices in graph
    g.addUndirectedEdge(1, 0);
    g.addUndirectedEdge(0, 2);
    g.addUndirectedEdge(2, 1);
    g.addUndirectedEdge(0, 3);
    g.addUndirectedEdge(1, 4);
    dfs(g, 0);
}
