#include "../../template.hpp"

vvi GetPresum(const vi& arr) {
    int n = arr.size();
    vvi presum(n + 1, vi(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        presum[i][i] = arr[i - 1];
    }
    for (int i = 1; i < n; ++i) {
        presum[i][i + 1] = arr[i - 1] + arr[i];
    }
    for (int k = 2; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            presum[i][j] = presum[i][j - 1] + arr[j - 1];
        }
    }
    return presum;
}

int MinCostToMergeStones(const vi& arr, int K) {
    int n = arr.size();
    if ((n - 1) % (K - 1)) return -1;

    vvi presum = GetPresum(arr);
    vvi dp(n + 1, vi(n + 1, INF));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 1; i + K - 1 <= n; ++i) {
        dp[i][i + K - 1] = presum[i][i + K - 1];
    }
    for (int k = K; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            for (int p = i; p < j; p++) {
                dp[i][j] = min({dp[i][j], dp[i][p] + dp[p + 1][j] + presum[i][j]});
            }
        }
    }
    return dp[1][n];
}

int MinCostToMergeStones2(const vi& arr, int K) {
    int n = arr.size();
    if ((n - 1) % (K - 1)) return -1;

    vvi presum = GetPresum(arr);
    vvvi dp(n + 1, vvi(n + 1, vi(K + 1, INF)));
    for (int i = 1; i <= n; ++i) {
        dp[i][i][1] = 0;
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            for (int q = 2; q <= K; ++q) {
                for (int p = i; p < j; ++p) {
                    dp[i][j][q] = min(dp[i][j][q], dp[i][p][q - 1] + dp[p + 1][j][1]);
                }
            }
            dp[i][j][1] = dp[i][j][K] + presum[i][j];
        }
    }
    return dp[1][n][1];
}

int main() { TimeMeasure _; __x();
    cout << MinCostToMergeStones({3,2,4,1}, 2) << '\n'; // 20
    cout << MinCostToMergeStones({3,2,4,1}, 3) << '\n'; // -1
    cout << MinCostToMergeStones({3,5,1,2,6}, 3) << '\n'; // 25
    cout << MinCostToMergeStones({6,4,9,9,9,7}, 3) << '\n'; // -1
    cout << MinCostToMergeStones({1,2}, 2) << '\n'; // 3
    cout << MinCostToMergeStones({9,8,3,2,9,4}, 2) << '\n'; // 88
    cout << '\n';
    cout << MinCostToMergeStones2({3,2,4,1}, 2) << '\n'; // 20
    cout << MinCostToMergeStones2({3,2,4,1}, 3) << '\n'; // -1
    cout << MinCostToMergeStones2({3,5,1,2,6}, 3) << '\n'; // 25
    cout << MinCostToMergeStones2({6,4,9,9,9,7}, 3) << '\n'; // -1
    cout << MinCostToMergeStones2({1,2}, 2) << '\n'; // 3
    cout << MinCostToMergeStones2({9,8,3,2,9,4}, 2) << '\n'; // 88
}
