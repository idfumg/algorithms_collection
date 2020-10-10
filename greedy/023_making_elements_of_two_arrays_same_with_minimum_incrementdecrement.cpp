#include "../template.hpp"

int naive(vi arr1, vi arr2, int i, vb& visited) {
    int n = arr1.size();
    if (i == n) {
        return 0;
    }
    int count = INF;
    for (int j = 0; j < n; ++j) {
        if (not visited[j]) {
            visited[j] = true;
            int diff = abs(arr1[i] - arr2[j]);
            count = min(count, naive(arr1, arr2, i + 1, visited) + diff);
            visited[j] = false;
        }
    }
    return count;
}

int naive(vi arr1, vi arr2) {
    vb visited(arr1.size());
    return naive(arr1, arr2, 0, visited);
}

int MinOpsToMakeTheSame(vi arr1, vi arr2) {
    sort(arr1);
    sort(arr2);
    int count = 0, n = arr1.size();
    for (int i = 0; i < n; ++i) {
        count += abs(arr1[i] - arr2[i]);
    }
    return count;
}

int main() { TimeMeasure _;
    cout << naive({3, 1, 1}, {1, 2, 2}) << '\n'; // 2
    cout << naive({3, 1, 1}, {1, 1, 2}) << '\n'; // 1
    cout << '\n';
    cout << MinOpsToMakeTheSame({3, 1, 1}, {1, 2, 2}) << '\n'; // 2
    cout << MinOpsToMakeTheSame({3, 1, 1}, {1, 1, 2}) << '\n'; // 1
}
