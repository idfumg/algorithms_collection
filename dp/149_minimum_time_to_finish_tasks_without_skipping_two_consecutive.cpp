#include "../template.hpp"

int rec(vi& arr, int n, bool skipped) {
    if (n == 0) return 0;
    if (n < 0) return INF;
    if (skipped) return rec(arr, n - 1, false) + arr[n - 1];
    return min(rec(arr, n - 1, false) + arr[n - 1], rec(arr, n - 1, true));
}

int rec(vi& arr) {
    return rec(arr, arr.size(), false);
}

int tab(vi& arr) {
    int n = arr.size();
    vvi dp(n + 1, vi(2));
    for (int i = 1; i <= n; ++i) {
        for (int skipped : {0, 1}) {
            if (skipped) {
                dp[i][true] = dp[i - 1][0] + arr[i - 1];
            }
            else {
                dp[i][false] = min(dp[i - 1][0] + arr[i - 1], dp[i - 1][1]);
            }
        }
    }
    return min(dp[n][0], dp[n][1]);
}

int main() { TimeMeasure _; __x();
    vi arr1 = {10, 5, 7, 10};
    vi arr2 = {10};
    vi arr3 = {10, 30};
    vi arr4 = {10, 5, 2, 4, 8, 6, 7, 10};
    vi arr5 = {467, 334, 500, 169, 724, 478, 358, 962, 464, 705, 145, 281};
    cout << rec(arr1) << endl;
    cout << rec(arr2) << endl;
    cout << rec(arr3) << endl;
    cout << rec(arr4) << endl;
    cout << rec(arr5) << endl;
    cout << endl;
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
    cout << tab(arr5) << endl;
}
