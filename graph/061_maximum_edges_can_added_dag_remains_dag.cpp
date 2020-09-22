#include "../template.hpp"

int dfs(vvi& graph, vb& visited, vi& ordering, int at, int pos) {
    visited[at] = true;
    for (int adj : graph[at]) {
        if (not visited[adj]) {
            pos = dfs(graph, visited, ordering, adj, pos);
        }
    }
    ordering[pos] = at;
    return pos - 1;
}

vi TopologicalSort(vvi& graph) {
    int n = graph.size(), pos = n - 1;
    vb visited(n);
    vi ordering(n);
    for (int i = 0; i < n; ++i) {
        if (not visited[i]) {
            pos = dfs(graph, visited, ordering, i, pos);
        }
    }
    return ordering;
}

int MaximumEdgesToAdd(vvi& graph) {
    int n = graph.size(), total = 0;
    vi ordering = TopologicalSort(graph);
    for (int i = 0; i < n; ++i) {
        total += n - i - 1 - graph[i].size();
    }
    return total;
}

void MaximumEdgesToPrint(vvi& graph) {
    int n = graph.size();
    vi ordering = TopologicalSort(graph);
    for (int i = 0; i < n; ++i) {
        int at = ordering[i];
        vb visited(n);
        for (int adj : graph[at]) {
            visited[adj] = true;
        }
        for (int j = i + 1; j < n; ++j) {
            if (not visited[ordering[j]]) {
                cout << at << '-' << ordering[j] << '\n';
            }
        }
    }
}

int main() { TimeMeasure _;
    vvi graph(6);
    graph[5].push_back(2);
    graph[5].push_back(0);
    graph[4].push_back(0);
    graph[4].push_back(1);
    graph[2].push_back(3);
    graph[3].push_back(1);
    cout << MaximumEdgesToAdd(graph) << endl;
    MaximumEdgesToPrint(graph);
    /*
5-4
5-3
5-1
4-2
4-3
2-1
2-0
3-0
1-0
*/
}
