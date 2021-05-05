#include "../../template.hpp"

using Graph = vvi;

void AddEdge(Graph& graph, int from, int to, int cost = 0) {
    graph[from].push_back(to);
    // graph[to].push_back(from);
    // graph.push_back({from, to});
    // graph[from].push_back({to, cost});
    // graph[to].push_back({from, cost});
    // graph.push_back({from, to, cost});
    // graph[from][to] = cost;
    // graph[to][from] = cost;
}

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
            if (dfs(graph, visited, i)) {
                return true;
            }
        }
    }
    return false;
}

bool CheckLoop(vi arr) {
    int n = arr.size();
    vvi graph(n);
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0 and (arr[i] % n > 0)) graph[i].push_back((i + arr[i]) % n);
        else if (arr[i] < 0 and (arr[i] % n > 0)) graph[i].push_back(abs(i - arr[i]) % n);
    }
    return DetectCycle(graph);
}

bool dfs(vi arr, vb& visited, int at) {
    int n = arr.size();
    visited[at] = true;
    if (arr[at] > 0) {
        int adj = (at + arr[at]) % n;
        if (adj == at) return false;
        if (visited[adj]) return true;
        return dfs(arr, visited, adj);
    }
    else if (arr[at] < 0) {
        int adj = (at - arr[at]) % n;
        if (adj < 0) adj += n;
        if (adj == at) return false;
        if (visited[adj]) return true;
        return dfs(arr, visited, adj);
    }
    return false;
}

bool CheckLoop2(vi arr) {
    int n = arr.size();
    vb visited(n);
    return dfs(arr, visited, 0);
}

int main() { TimeMeasure _;
    vi arr1 = {2, -1, 1, 2, 2};
    vi arr2 = {1, 1, 1, 1, 1, 1};
    vi arr3 = {1, 2};

    cout << CheckLoop(arr1) << endl; // 1
    cout << CheckLoop(arr2) << endl; // 1
    cout << CheckLoop(arr3) << endl; // 0
    cout << endl;
    cout << CheckLoop2(arr1) << endl; // 1
    cout << CheckLoop2(arr2) << endl; // 1
    cout << CheckLoop2(arr3) << endl; // 0
}
