#include "../../template.hpp"

int MaxElementsMadeEqual(vi arr, int K) { // O(n^2)
    sort(arr); // 1,3,5,5 // [i][j] - min increases to make [i..j] the same
    int n = arr.size();
    int ans = 1;
    vvi dp(n + 1, vi(n + 1));
    for (int i = 1; i <= n; ++i) {
        dp[i][i] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        int diff = abs(arr[i - 1] - arr[i - 2]);
        dp[i - 1][i] = diff;
        if (diff <= K) {
            ans = max(ans, 2);
        }
    }
    for (int k = 2; k < n; ++k) {
        for (int i = 1, j = i + k; j <= n; ++i, ++j) {
            dp[i][j] = dp[i][j - 1] + abs(j - i) * abs(arr[j - 2] - arr[j - 1]);
            if (dp[i][j] <= K) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << MaxElementsMadeEqual({2,4,9}, 3) << '\n'; // 2
    cout << MaxElementsMadeEqual({5,5,3,1}, 5) << '\n'; // 3
    cout << MaxElementsMadeEqual({5,5,3,1}, 6) << '\n'; // 4
    cout << MaxElementsMadeEqual({2,4,5,6,7,8,8,8,8,8}, 3) << '\n'; // 7
}
