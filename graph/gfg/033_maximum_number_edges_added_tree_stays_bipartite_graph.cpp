#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void FindMaxEdgesBFS(Graph& graph) {
    int n = graph.size();
    int currentEdges = 0;

    vi color(n, -1);
    color[1] = 1;

    vi colorCount = {0, 1};

    qi q;
    q.push(1);

    while (not q.empty()) {
        int at = q.front(); q.pop();
        for (int adj : graph[at]) {
            if (color[at] == 1) {
                ++currentEdges;
            }
            if (color[adj] == -1) {
                color[adj] = 1 - color[at];
                ++colorCount[color[adj]];
                q.push(adj);
            }
            else if (color[adj] == color[at]) {
                cout << "Error! Graph is not a bipartite graph!" << '\n';
                return;
            }
        }
    }
    int totalEdges = colorCount[0] * colorCount[1];
    cout << totalEdges - currentEdges << '\n';
}

bool dfs(Graph& graph, vi& color, vi& colorCount, int at, int& currentEdges) {
    for (int adj : graph[at]) {
        if (color[at] == 1) {
            ++currentEdges;
        }
        if (color[adj] == -1) {
            color[adj] = 1 - color[at];
            ++colorCount[color[adj]];
            if (not dfs(graph, color, colorCount, adj, currentEdges)) return false;
        }
        else if (color[adj] == color[at]) {
            return false;
        }
    }
    return true;
}

void FindMaxEdgesDFS(Graph& graph) {
    int n = graph.size();
    int currentEdges = 0;

    vi color(n, -1);
    vi colorCount = {0, 1};

    for (int i = 1; i < n; ++i) {
        if (color[i] == -1) {
            color[1] = 1;
            if (not dfs(graph, color, colorCount, i, currentEdges)) {
                cout << "Error! Graph is not a bipartite graph!" << '\n';
                return;
            }
        }
    }

    int totalEdges = colorCount[0] * colorCount[1];
    cout << totalEdges - currentEdges << '\n';
}

int main() { TimeMeasure _;
    {
        Graph graph(4);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 1, 3);
        FindMaxEdgesBFS(graph);
        FindMaxEdgesDFS(graph);
    }
    {
        Graph graph(6);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 1, 3);
        AddEdge(graph, 2, 4);
        AddEdge(graph, 3, 5);
        FindMaxEdgesBFS(graph);
        FindMaxEdgesDFS(graph);
    }
}
