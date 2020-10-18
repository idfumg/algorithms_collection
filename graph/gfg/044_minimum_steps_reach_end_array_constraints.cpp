#include "../../template.hpp"

void bfs(vi arr) {
    int n = arr.size();
    qi q;
    vi visited(n);
    vi dist(n, INF);
    dist[0] = 0;
    q.push(0);
    unordered_map<int, vi> indicies;
    for (int i = 0; i < n; ++i) {
        indicies[arr[i]].push_back(i);
    }
    while (not q.empty()) {
        int at = q.front(); q.pop();
        visited[at] = true;
        for (int adj : {at - 1, at + 1}) {
            if (adj >= 0 and adj < n and not visited[adj]) {
                dist[adj] = min(dist[adj], dist[at] + 1);
                q.push(adj);
            }
        }
        for (int adj : indicies[arr[at]]) {
            if (adj >= 0 and adj < n and not visited[adj]) {
                dist[adj] = min(dist[adj], dist[at] + 1);
                q.push(adj);
            }
        }
    }
    cout << dist.back() << endl;
}

int main() { TimeMeasure _;
    vi arr1 = {5, 4, 2, 5, 0};
    vi arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 5, 4, 3, 6, 0, 1, 2, 3, 4, 5, 7};
    bfs(arr1);
    bfs(arr2);
}
