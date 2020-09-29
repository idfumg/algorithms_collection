#include "../template.hpp"

using Graph = vvi;

void AddDirectedEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
}

bool dfs(Graph& graph, vi& color, int at) {
    color[at] = 1;
    for (int adj : graph[at]) {
        if (color[adj] == -1 and dfs(graph, color, adj)) return true;
        else if (color[adj] == 1) return true;
    }
    color[at] = 2;
    return false;
}

bool DetectCycle(Graph& graph) {
    int n = graph.size();
    vi color(n, -1);
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            if (dfs(graph, color, i)) return true;
        }
    }
    return false;
}

int main() { TimeMeasure _;
    {
        Graph graph(4);
        AddDirectedEdge(graph, 0, 1);
        AddDirectedEdge(graph, 0, 2);
        AddDirectedEdge(graph, 1, 2);
        AddDirectedEdge(graph, 2, 0);
        AddDirectedEdge(graph, 2, 3);
        AddDirectedEdge(graph, 3, 3);
        cout << DetectCycle(graph) << '\n';
    }
    {
        Graph graph(4);
        AddDirectedEdge(graph, 0, 1);
        AddDirectedEdge(graph, 0, 2);
        AddDirectedEdge(graph, 1, 2);
        AddDirectedEdge(graph, 2, 3);
        cout << DetectCycle(graph) << '\n';
    }
    {
        Graph graph(4);
        AddDirectedEdge(graph, 0, 1);
        AddDirectedEdge(graph, 0, 2);
        AddDirectedEdge(graph, 1, 2);
        AddDirectedEdge(graph, 2, 0);
        AddDirectedEdge(graph, 2, 3);
        AddDirectedEdge(graph, 3, 3);
        cout << DetectCycle(graph) << '\n';
    }
}
