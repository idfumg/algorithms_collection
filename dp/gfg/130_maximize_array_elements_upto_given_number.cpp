#include "../../template.hpp"

int rec(vi& arr, int maxsum, int idx, int sum) {
    int n = arr.size();
    if (sum < 0 or sum > maxsum) return -INF;
    if (idx == n) return sum;
    return max(rec(arr, maxsum, idx + 1, sum + arr[idx]),
               rec(arr, maxsum, idx + 1, sum - arr[idx]));
}

int rec(vi& arr, int number, int sum) {
    return rec(arr, sum, 0, number);
}

int tab(vi& arr, int num, int sum) {
    int n = arr.size();
    vvi dp(n + 1, vi(sum + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= sum; ++j) {
            if (i == 1) {
                if (num - arr[i - 1] == j or num + arr[i - 1] == j) {
                    dp[i][j] = 1;
                }
            }
            else {
                if (j - arr[i - 1] >= 0) {
                    dp[i][j] = dp[i][j] or dp[i - 1][j - arr[i - 1]];
                }
                if (j + arr[i - 1] <= sum) {
                    dp[i][j] = dp[i][j] or dp[i - 1][j + arr[i - 1]];
                }
            }
        }
    }
    for (int i = sum; i >= 0; --i) {
        if (dp[n][i]) return i;
    }
    return -1;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 1, 7}; int n1 = 3, sum1 = 7;
    vi arr2 = {3, 10, 6, 4, 5}; int n2 = 1, sum2 = 15;
    cout << rec(arr1, n1, sum1) << endl; // 7
    cout << rec(arr2, n2, sum2) << endl; // 9
    cout << '\n';
    cout << tab(arr1, n1, sum1) << endl; // 7
    cout << tab(arr2, n2, sum2) << endl; // 9
}
