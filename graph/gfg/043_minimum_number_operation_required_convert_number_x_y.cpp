#include "../../template.hpp"

int MinimumOpsToTransfrom(int from, int to) {
    deque<int> q;
    q.push_back(from);

    unordered_map<int, int> dist;
    dist[from] = 0;

    unordered_map<int, bool> visited;

    while (not q.empty()) {
        int at = q.front(); q.pop_front();
        if (at == to) {
            return dist[to];
        }
        visited[at] = true;
        for (int adj : {2 * at, at - 1}) {
            if (not visited[adj]) {
                if (not dist.count(adj)) {
                    dist[adj] = INF;
                }
                dist[adj] = min(dist[adj], dist[at] + 1);
                q.push_back(adj);
            }
        }
    }

    return dist[to];
}

int main() { TimeMeasure _;
    cout << MinimumOpsToTransfrom(4, 7) << '\n'; // 2
    cout << MinimumOpsToTransfrom(2, 5) << '\n'; // 4
}
