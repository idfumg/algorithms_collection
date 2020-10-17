#include "../../template.hpp"

void rec(vi& arr, int k, int& res, int from, int partitions, int cost) {
    if (partitions == k and from == arr.size()) {
        res = min(res, cost);
        return;
    }
    if (from >= arr.size()) return;

    for (int i = from; i < arr.size(); ++i) {
        int partition_cost = (arr[i] - arr[from]) * (arr[i] - arr[from]);
        rec(arr, k, res, i + 1, partitions + 1, cost + partition_cost);
    }
}

int rec(vi& arr, int k) {
    int res = INF;
    rec(arr, k, res, 0, 0, 0);
    return res;
}

int tab(vi& arr, int K) {
    int n = arr.size();
    vvi dp(n + 1, vi(K + 1, INF));
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int k = 1; k <= K; ++k) {
            for (int m = 0; m < i; ++m) {
                int cost = (arr[i - 1] - arr[m]) * (arr[i - 1] - arr[m]);
                dp[i][k] = min({dp[i][k], dp[m][k - 1] + cost});
            }
        }
    }
    return dp[n][K];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 5, 8, 10}; int k1 = 2;
    vi arr2 = {1, 5, 8, 10}; int k2 = 3;
    cout << rec(arr1, k1) << endl;
    cout << rec(arr2, k2) << endl;
    cout << tab(arr1, k1) << endl;
    cout << tab(arr2, k2) << endl;
}
