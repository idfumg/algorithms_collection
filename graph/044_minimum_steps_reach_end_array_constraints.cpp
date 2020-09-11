#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

int MinStepsToReachTheEnd(vi& arr) {
    int n = size(arr);

    unordered_map<int, vi> m;
    for (int i = 0; i < n; ++i) m[arr[i]].push_back(i);

    deque<int> q;
    q.push_back(0);

    vi dist(n, -1);
    dist[0] = 0;

    while (not q.empty()) {
        int i = q.front(); q.pop_front();
        for (int at : m[arr[i]]) {
            if (dist[at] == -1) {
                q.push_back(at);
                dist[at] = dist[i] + 1;
            }
        }
        if (i - 1 >= 0 and dist[i - 1] == -1) {
            q.push_back(i - 1);
            dist[i - 1] = dist[i] + 1;
        }
        if (i + 1 < n and dist[i + 1] == -1) {
            q.push_back(i + 1);
            dist[i + 1] = dist[i] + 1;
        }
    }
    return dist[n - 1];
}

int main() { TimeMeasure _;
    vi arr1 = {5, 4, 2, 5, 0};
    vi arr2 = {0, 1, 2, 3, 4, 5, 6, 7, 5, 4, 3, 6, 0, 1, 2, 3, 4, 5, 7};
    cout << MinStepsToReachTheEnd(arr1) << endl;
    cout << MinStepsToReachTheEnd(arr2) << endl;
}
