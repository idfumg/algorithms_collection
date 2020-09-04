#include "../../template.hpp"

// find
// 1) non-decreasing subsequence
// 2) with length k
// 3) with minimum sum

int tab(vi& arr, int K) {
    int n = arr.size(), mini = INF;
    vvi dp(K + 1, vi(n + 1, INF));
    for (int k = 1; k <= K; ++k) {
        for (int i = 1; i <= n; ++i) {
            if (k == 1) {
                dp[k][i] = arr[i - 1];
            }
            else {
                for (int j = 1; j < i; ++j) {
                    if (arr[i - 1] > arr[j - 1]) {
                        dp[k][i] = min(dp[k][i], dp[k - 1][j] + arr[i - 1]);
                    }
                }
            }
            if (k == K) {
                mini = min(mini, dp[k][i]);
            }
        }
    }
    return mini;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k1 = 3;
    vi arr2 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k2 = 4;
    vi arr3 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k3 = 5;

    print(tab(arr1, k1)); // 39
    print(tab(arr2, k2)); // 120
    print(tab(arr3, k3)); // 206
}
