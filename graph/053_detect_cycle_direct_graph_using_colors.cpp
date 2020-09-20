#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void AddEdge(vvi& graph, int from, int to) {
    graph[from].push_back(to);
}

bool dfs(vvi& graph, vi& visited, int at) {
    visited[at] = 1; // nonfinished state
    for (int adj : graph[at]) {
        if (visited[adj] == 1) { // current stack trace
            return true;
        }
        if (visited[adj] != 2) { // not already performed
            if (dfs(graph, visited, adj)) return true;
        }
    }
    visited[at] = 2; // has been performed
    return false;
}

void DetectCycle(vvi& graph) {
    int n = size(graph);
    vi visited(n);
    for (int i = 0; i <n; ++i) {
        if (not visited[i]) {
            if (dfs(graph, visited, i)) {
                cout << "Cycle detected" << endl;
                return;
            }
        }
    }
    cout << "Cycle has not detected" << endl;
}

int main() { TimeMeasure _;
    {
        vvi graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 0);
        AddEdge(graph, 2, 3);
        AddEdge(graph, 3, 3);
        DetectCycle(graph);
    }
    {
        vvi graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        DetectCycle(graph);
    }
    {
        vvi graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 0);
        AddEdge(graph, 2, 3);
        AddEdge(graph, 3, 3);
        DetectCycle(graph);
    }
}
