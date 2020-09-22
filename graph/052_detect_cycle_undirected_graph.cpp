#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void AddEdge(vvi& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

bool dfs(vvi& graph, vb& visited, int at, int parent) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (adj == parent) continue;
        if (visited[adj]) return true;
        if (dfs(graph, visited, adj, at)) return true;
    }
    return false;
}

void DetectCycle(vvi& graph) {
    int n = graph.size();
    vb visited(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            if(dfs(graph, visited, i, -1)) {
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
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        AddEdge(graph, 0, 2);
        DetectCycle(graph); // yes
    }
    {
        vvi graph(4);
        AddEdge(graph, 0, 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 2, 3);
        DetectCycle(graph); // no
    }
    {
        vvi graph(5);
        AddEdge(graph, 1, 0);
        AddEdge(graph, 0, 2);
        AddEdge(graph, 2, 1);
        AddEdge(graph, 0, 3);
        AddEdge(graph, 3, 4);
        DetectCycle(graph); // yes
    }
}
