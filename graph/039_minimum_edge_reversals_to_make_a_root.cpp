#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool IsPathExists(Graph& graph, int from, int to) {
    for (const auto& edge : graph.edges(from)) {
        if (edge.to == to) {
            return true;
        }
    }
    return false;
}

void dfs(Graph& graph, Graph& graphReal, vb& visited, int at, int& count) {
    visited[at] = true;
    for (const auto& edge : graph.edges(at)) {
        if (not visited[edge.to]) {
            if (IsPathExists(graphReal, edge.from, edge.to)) {
                --count;
            }
            dfs(graph, graphReal, visited, edge.to, count);
        }
    }
}

void FindRootAndHowManyChanges(Graph& graph, Graph& graphReal) {
    int n = size(graph), vertex = -1, changes = INF;
    for (int i = 0; i < n; ++i) {
        vb visited(n);
        int count = n - 1;
        dfs(graph, graphReal, visited, i, count);
        if (changes > count) {
            changes = count;
            vertex = i;
        }
    }
    cout << vertex << ' ' << changes << endl;
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

    FindRootAndHowManyChanges(graph, graphReal);
}
