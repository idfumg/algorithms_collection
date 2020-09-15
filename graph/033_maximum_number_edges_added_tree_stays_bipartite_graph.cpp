#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void AddEdge(Graph& graph, int from, int to) {
    graph.addDirectedEdge(from - 1, to - 1);
}

void FindMaxEdgesBFS(Graph& graph) {
    queue<int> q;
    q.push(0);

    vi colors(size(graph)), color = {1, 0};
    colors[0] = 0;

    while (not q.empty()) {
        int at = q.front(); q.pop();
        for (const auto& edge : graph.edges(at)) {
            colors[edge.to] = 1 - colors[at];
            color[colors[edge.to]]++;
            q.push(edge.to);
        }
    }
    cout << color[0] * color[1] - (size(graph) - 1) << endl;
}

void dfs(Graph& graph, int at, int color, vi& colors) {
    colors[color]++;
    for (const auto& edge : graph.edges(at)) {
        dfs(graph, edge.to, 1 - color, colors);
    }
}

void FindMaxEdgesDFS(Graph& graph) {
    vi colors(2);
    dfs(graph, 0, 0, colors);
    cout << colors[0] * colors[1] - (size(graph) - 1) << endl;
}

int main() { TimeMeasure _;
    {
        Graph graph(3);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 1, 3);
        FindMaxEdgesBFS(graph);
        FindMaxEdgesDFS(graph);
    }
    {
        Graph graph(5);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 1, 3);
        AddEdge(graph, 2, 4);
        AddEdge(graph, 3, 5);
        FindMaxEdgesBFS(graph);
        FindMaxEdgesDFS(graph);
    }
}
