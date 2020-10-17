#include "../../template.hpp"

int GetMinOpsToSorted(vi arr) {
    reverse(arr);
    int small = *min_element(arr.begin(), arr.end());
    int large = *max_element(arr.begin(), arr.end());
    int n = arr.size();
    vvi dp(n + 1, vi(large + 1));
    for (int j = small; j <= large; ++j) {
        dp[1][j] = abs(arr[0] - j);
    }
    for (int i = 2; i <= n; ++i) {
        int minimum = INF; // minimum of dp[i - 1][small .. j]
        for (int j = small; j <= large; ++j) {
            minimum = min(minimum, dp[i - 1][j]);
            dp[i][j] = minimum + abs(arr[i - 1] - j);
        }
    }
    int ans = INF;
    for (int j = small; j <= large; ++j) {
        ans = min(ans, dp[n][j]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << GetMinOpsToSorted({1,2,1,4,3}) << '\n'; // 2
    cout << GetMinOpsToSorted({1,2,2,100}) << '\n'; // 0
}
