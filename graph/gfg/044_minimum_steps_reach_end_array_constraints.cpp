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

int bfs(vi arr) {
    unordered_map<int, vi> tab;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        tab[arr[i]].push_back(i);
    }

    deque<int> q;
    q.push_back(0);

    vi dist(n, INF);
    dist[0] = 0;

    vb visited(n);

    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        visited[at] = true;

        for (int adj : tab[arr[at]]) {
            if (not visited[adj]) {
                dist[adj] = min(dist[adj], dist[at] + 1);
                q.push_back(adj);
            }
        }

        for (int adj : {at - 1, at + 1}) {
            if (adj >= 0 and adj < n and not visited[adj]) {
                dist[adj] = min(dist[adj], dist[at] + 1);
                q.push_back(adj);
            }
        }
    }

    return dist[n - 1];
}

int main() { TimeMeasure _;
    vi arr1 = {5, 4, 2, 5, 0};
    vi arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 5, 4, 3, 6, 0, 1, 2, 3, 4, 5, 7};
    cout << bfs(arr1) << endl; // 2
    cout << bfs(arr2) << endl; // 5
}
