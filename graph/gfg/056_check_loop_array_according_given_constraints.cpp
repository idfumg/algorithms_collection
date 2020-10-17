#include "../../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool dfs(vvi& graph, vi& visited, int at) {
    visited[at] = 1;
    for (int adj : graph[at]) {
        if (visited[adj] == 1) return true;
        if (visited[adj] == 2) continue;
        if (dfs(graph, visited, adj)) return true;
    }
    visited[at] = 2;
    return false;
}

bool DetectCycle(vvi& graph) {
    int n = graph.size();

    vi visited(n);
    for (int i = 0; i < n; ++i) {
        if (visited[i] == 0) {
            if (dfs(graph, visited, i)) return true;
        }
    }
    return false;
}

void CheckLoop(vi& arr) {
    int n = arr.size();

    vvi graph(n);
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0 and (arr[i] % n > 0)) {
            graph[i].push_back((i + arr[i]) % n);
        }
        else if (arr[i] < 0 and (arr[i] % n > 0)) {
            graph[i].push_back(abs(i - arr[i]) % n);
        }
    }

    if (DetectCycle(graph)) {
        cout << "Cycle detected" << endl;
    }
    else {
        cout << "Cycle has not detected" << endl;
    }
}

int main() { TimeMeasure _;
    vi arr1 = {2, -1, 1, 2, 2};
    vi arr2 = {1, 1, 1, 1, 1, 1};
    vi arr3 = {1, 2};

    CheckLoop(arr1);
    CheckLoop(arr2);
    CheckLoop(arr3);
}
