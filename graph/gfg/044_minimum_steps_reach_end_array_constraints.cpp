#include "../../template.hpp"

void bfs(vi& arr) {
    int n = arr.size();
    vb visited(n);
    vi dist(n, INF);
    dist[0] = 0;
    qi q;
    q.push(0);
    unordered_map<int, vi> idx;
    for (int i = 0; i < n; ++i) {
        idx[arr[i]].push_back(i);
    }
    while (not q.empty()) {
        int at = q.front(); q.pop();
        visited[at] = true;

        int x = at - 1;
        int y = at + 1;
        int z = arr[at];

        if (idx.count(z)) {
            for (int pos : idx[z]) {
                if (not visited[pos]) {
                    dist[pos] = min(dist[pos], dist[at] + 1);
                    q.push(pos);
                }
            }
        }
        if (x >= 0 and not visited[x]) {
            dist[x] = min(dist[x], dist[at] + 1);
            q.push(x);
        }
        if (y < n and not visited[y]) {
            dist[y] = min(dist[y], dist[at] + 1);
            q.push(y);
        }
    }
    cout << dist[n - 1] << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {5, 4, 2, 5, 0};
    vi arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 5, 4, 3, 6, 0, 1, 2, 3, 4, 5, 7};
    bfs(arr1);
    bfs(arr2);
}
