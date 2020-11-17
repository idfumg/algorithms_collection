#include "../../template.hpp"

void MaximumsOfAllSubarrays(vi arr, int K) {
    int n = arr.size();
    vvi dp(n, vi(n));
    for (int i = 1; i < n; ++i) {
        dp[i - 1][i] = max(arr[i - 1], arr[i]);
    }
    for (int k = 2; k < K; ++k) {
        for (int i = 0, j = i + k; j < n; ++i, ++j) {
            dp[i][j] = max(dp[i][j - 1], arr[j]);
        }
    }
    for (int i = 0, j = K - 1; j < n; ++i, ++j) {
        cout << dp[i][j] << ' ';
    }
    cout << endl;
}

int main() { TimeMeasure _;
    MaximumsOfAllSubarrays({1, 2, 3, 1, 4, 5, 2, 3, 6}, 3); // O(nk)
    MaximumsOfAllSubarrays({8, 5, 10, 7, 9, 4, 15, 12, 90, 13}, 4);
}
