#include "../../template.hpp"

vvi getMins(vi arr) {
    int n = arr.size();
    vvi dp(n + 2, vi(n + 1, INF));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = INF;
            else if (i == j) dp[i][j] = arr[i - 1];
            else if (j - i == 1) dp[i][j] = min(arr[i - 1], arr[j - 1]);
            else dp[i][j] = min(arr[i - 1], dp[i + 1][j]);
        }
    }
    return dp;
}

vvi getMaxs(vi arr) {
    int n = arr.size();
    vvi dp(n + 2, vi(n + 1, -INF));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) dp[i][j] = -INF;
            else if (i == j) dp[i][j] = arr[i - 1];
            else if (j - i == 1) dp[i][j] = max(arr[i - 1], arr[j - 1]);
            else dp[i][j] = max(arr[i - 1], dp[i + 1][j]);
        }
    }
    return dp;
}

int rec(vi arr, int i, int j) {
    if (i >= j) return 0;
    vvi mins = getMins(arr);
    vvi maxs = getMaxs(arr);
    if (2 * mins[i][j] > maxs[i][j]) return 0;
    return min(rec(arr, i + 1, j), rec(arr, i, j - 1)) + 1;
}

int rec(vi arr) {
    return rec(arr, 1, arr.size());
}

int tab(vi arr) {
    int n = arr.size();
    vvi dp(n + 1, vi(n + 1));
    vvi mins = getMins(arr);
    vvi maxs = getMaxs(arr);
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (2 * mins[i][j] > maxs[i][j]) dp[i][j] = 0;
            else dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 5, 100, 9, 10, 11, 12, 15, 200}; // 4
    vi arr2 = {4, 7, 5, 6}; // 0
    vi arr3 = {20, 7, 5, 6}; // 1
    vi arr4 = {20, 4, 1, 3}; // 3

    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << rec(arr3) << endl;
    cout << rec(arr4) << endl;
    cout << '\n';
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
}
