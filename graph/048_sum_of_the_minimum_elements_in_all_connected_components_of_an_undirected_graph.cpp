#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void AddEdge(vvi& graph, int from, int to) {
    graph[from].push_back(to);
    graph[to].push_back(from);
}

void dfs(vvi& graph, vi& arr, vb& visited, int at, int& mini) {
    visited[at] = true;
    mini = min(mini, arr[at - 1]);
    for (int node : graph[at]) {
        if (not visited[node]) {
            dfs(graph, arr, visited, node, mini);
        }
    }
}

void FindSum(vi& arr, vvi& graph) {
    int res = 0, n = arr.size();
    vb visited(n + 1);
    for (int i = 1; i < n; ++i) {
        if (not visited[i]) {
            int mini = INF;
            dfs(graph, arr, visited, i, mini);
            res += mini;
        }
    }
    cout << res << endl;
}

int main() { TimeMeasure _;
    {
        vi arr = {2,5,3,4,8};
        vvi graph(arr.size() + 1);
        AddEdge(graph, 1, 4);
        AddEdge(graph, 4, 1);
        FindSum(arr, graph);
    }
    {
        vi arr = {1, 6, 2, 7, 3, 8, 4, 9, 5, 10} ;
        vvi graph(arr.size() + 1);
        AddEdge(graph, 1, 2);
        AddEdge(graph, 3, 4);
        AddEdge(graph, 5, 6);
        AddEdge(graph, 7, 8);
        AddEdge(graph, 9, 10);
        FindSum(arr, graph);
    }
}
