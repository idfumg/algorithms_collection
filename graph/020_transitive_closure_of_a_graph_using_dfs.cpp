#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void dfs(Graph& graph, vvb& reach, int from, int to) {
    reach[from][to] = true;
    for (const auto& edge : graph.edges(to)) {
        if (not reach[from][edge.to]) {
            dfs(graph, reach, from, edge.to);
        }
    }
}

void TransitiveClosure(Graph& graph) {
    int n = graph.size();
    vvb reach(n, vb(n));
    for (int i = 0; i < n; ++i) {
        dfs(graph, reach, i, i);
    }
    cout << reach << endl;
}

int main() { TimeMeasure _;
    Graph g(4);
    g.addDirectedEdge(0, 1);
    g.addDirectedEdge(0, 2);
    g.addDirectedEdge(1, 2);
    g.addDirectedEdge(2, 0);
    g.addDirectedEdge(2, 3);
    g.addDirectedEdge(3, 3);
    TransitiveClosure(g);
}

/*
  Transitive closure of above graphs is
  1 1 1 1
  1 1 1 1
  1 1 1 1
  0 0 0 1
*/
