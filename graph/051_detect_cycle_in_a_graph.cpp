#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool dfs(vvi& graph, vb& visited, vb& onstack, int at) {
    visited[at] = true;
    onstack[at] = true;
    for (int adj : graph[at]) {
        if (onstack[adj]) {
            return true;
        }
        if (not visited[adj]) {
            if (dfs(graph, visited, onstack, adj)) return true;
        }
    }
    onstack[at] = false;
    return false;
}

void DetectCycle(vvi& graph) {
    int n = size(graph);
    vb visited(n), onstack(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            if (dfs(graph, visited, onstack, i)) {
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
        graph[0].push_back(1);
        graph[0].push_back(2);
        graph[1].push_back(2);
        graph[2].push_back(0);
        graph[2].push_back(3);
        graph[3].push_back(3);
        DetectCycle(graph); // yes
    }
    {
        vvi graph(4);
        graph[0].push_back(1);
        graph[0].push_back(2);
        graph[1].push_back(2);
        graph[2].push_back(3);
        DetectCycle(graph); // no
    }
    {
        vvi graph(4);
        graph[0].push_back(1);
        graph[0].push_back(2);
        graph[1].push_back(2);
        graph[2].push_back(0);
        graph[2].push_back(3);
        graph[3].push_back(3);
        DetectCycle(graph); // yes
    }
}
