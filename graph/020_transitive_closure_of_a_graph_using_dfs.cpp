#include "../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

void dfs(Graph& graph, vvb& reach, int at, int root) {
    reach[root][at] = true;
    for (int adj : graph[at]) {
        if (not reach[root][adj]) {
            dfs(graph, reach, adj, root);
        }
    }
}

void TransitiveClosure(Graph& graph) {
    int n = graph.size();
    vvb reach(n, vb(n));
    for (int i = 0; i < n; ++i) {
        dfs(graph, reach, i, i);
    }
    cout << reach << '\n';
}

int main() { TimeMeasure _;
    Graph graph(4);
    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 2);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 2, 0);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 3);
    TransitiveClosure(graph);
}
/*
  Transitive closure of above graphs is
  1 1 1 1
  1 1 1 1
  1 1 1 1
  0 0 0 1
*/
