#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

void bfs(vi& arr) {
    int n = size(arr);

    qi q;
    q.push(0);

    unordered_map<int, vi> idxs;
    for (int i = 0; i < n; ++i) idxs[arr[i]].push_back(i);

    vi dist(n, -1);
    dist[0] = 0;

    while (not q.empty()) {
        int at = q.front(); q.pop();

        for (int idx : idxs[arr[at]]) {
            if (dist[idx] == -1) {
                dist[idx] = dist[at] + 1;
                q.push(idx);
            }
        }
        if (at > 0 and dist[at - 1] == -1) {
            dist[at - 1] = dist[at] + 1;
            q.push(at - 1);
        }
        if (at + 1 < n and dist[at + 1] == -1) {
            dist[at + 1] = dist[at] + 1;
            q.push(at + 1);
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
