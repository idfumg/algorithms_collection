#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void dfs(Graph& graph, vi& colors, int at, int color, int parent) {
    ++colors[color];
    for (const auto& edge : graph.edges(at)) {
        if (edge.to != parent) {
            dfs(graph, colors, edge.to, 1 - color, at);
        }
    }
}

int FindMaxEdges(Graph& graph) {
    int n = size(graph);
    vi colors(2);
    dfs(graph, colors, 1, 0, -1);
    return colors[0] * colors[1] - (n - 1 - 1);
}

int main() { TimeMeasure _;
    {
        Graph graph(3, 1);
        graph.addUndirectedEdge(1, 2);
        graph.addUndirectedEdge(1, 3);
        cout << FindMaxEdges(graph) << endl;
    }

    {
        Graph graph(5, 1);
        graph.addUndirectedEdge(1, 2);
        graph.addUndirectedEdge(1, 3);
        graph.addUndirectedEdge(2, 4);
        graph.addUndirectedEdge(3, 5);
        cout << FindMaxEdges(graph) << endl;
    }
}
