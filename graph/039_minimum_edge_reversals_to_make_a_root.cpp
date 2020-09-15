#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool IsRealEdge(Graph& graph, int from, int to) {
    const auto& edges = graph.edges(from);
    const auto pred = [&to](const auto& edge){ return edge.to == to; };
    return find_if(begin(edges), end(edges), pred) != end(edges);
}

void dfs(Graph& graph, Graph& graphReal, vb& visited, int at, int& count) {
    visited[at] = true;
    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            if (not IsRealEdge(graphReal, at, edge.to)) ++count;
            dfs(graph, graphReal, visited, edge.to, count);
        }
    }
}

void MinReversalsToMakeRoot(Graph& graph, Graph& graphReal) {
    int n = size(graph), reversals = INF, root = -1;
    for (int at = 0; at < n; ++at) {
        int count = 0;
        vb visited(n);
        dfs(graph, graphReal, visited, at, count);
        if (count < reversals) {
            reversals = count;
            root = at;
        }
    }
    cout << root << ' ' << reversals << '\n';
}

int main() { TimeMeasure _;
    Graph graph(8);
    graph.addUndirectedEdge(0, 1);
    graph.addUndirectedEdge(2, 1);
    graph.addUndirectedEdge(3, 2);
    graph.addUndirectedEdge(3, 4);
    graph.addUndirectedEdge(5, 4);
    graph.addUndirectedEdge(5, 6);
    graph.addUndirectedEdge(7, 6);

    Graph graphReal(8);
    graphReal.addDirectedEdge(0, 1);
    graphReal.addDirectedEdge(2, 1);
    graphReal.addDirectedEdge(3, 2);
    graphReal.addDirectedEdge(3, 4);
    graphReal.addDirectedEdge(5, 4);
    graphReal.addDirectedEdge(5, 6);
    graphReal.addDirectedEdge(7, 6);

    MinReversalsToMakeRoot(graph, graphReal);
}
