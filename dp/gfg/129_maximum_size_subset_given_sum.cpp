#include "../../template.hpp"

int rec(vi arr, int target, int n, int len) {
    if (target == 0) return len;
    if (n == 0 or target <= 0) return 0;
    return max(rec(arr, target - arr[n - 1], n - 1, len + 1), rec(arr, target, n - 1, len));
}

int rec(vi arr, int target) {
    return rec(arr, target, arr.size(), 0);
}

int tab(vi arr, int target) {
    int n = arr.size();
    vvvi dp(target + 1, vvi(n + 1, vi(n + 1)));
    for (int i = 0; i <= target; ++i) {
        for (int j = 0; j <= n; ++j) {
            for (int k = 0; k <= n; ++k) {
                if (i == 0) dp[i][j][k] = k;
                else if (j == 0) dp[i][j][k] = 0;
                else dp[i][j][k] = max(dp[i][j - 1][k], i >= arr[j - 1] ? dp[i - arr[j - 1]][j - 1][k + 1] : 0);
            }
        }
    }
    return dp[target][n][0];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 3, 5, 7, 10, 15}; int sum1 = 10; // 3
    vi arr2 = {1, 2, 3, 4, 5}; int sum2 = 4; // 2
    vi arr3 = {2, 3, 5, 10}; int sum3 = 20; // 4

    cout << rec(arr1, sum1) << endl;
    cout << rec(arr2, sum2) << endl;
    cout << rec(arr3, sum3) << endl;
    cout << '\n';
    cout << tab(arr1, sum1) << endl;
    cout << tab(arr2, sum2) << endl;
    cout << tab(arr3, sum3) << endl;
}
