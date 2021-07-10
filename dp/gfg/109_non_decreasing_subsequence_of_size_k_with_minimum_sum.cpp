#include "../../template.hpp"

int naive(vi arr, int k) {
    int n = arr.size();
    int ans = INF;
    for (int i = 1; i < (1 << n); ++i) {
        vi subseq;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                subseq.push_back(arr[j]);
            }
        }
        if (is_sorted(subseq.begin(), subseq.end()) and subseq.size() == k) {
            ans = min(ans, accumulate(subseq.begin(), subseq.end(), 0));
        }
    }
    return ans;
}

int rec(vi arr, int k, int n, int prev) {
    if (k == 0) return 0;
    if (n == 0) return INF;
    if (prev == INF) return min(rec(arr, k - 1, n - 1, n) + arr[n - 1], rec(arr, k, n - 1, prev));
    if (arr[n - 1] <= arr[prev - 1]) return min(rec(arr, k - 1, n - 1, n) + arr[n - 1], rec(arr, k, n - 1, prev));
    return rec(arr, k, n - 1, prev);
}

int rec(vi arr, int k) {
    return rec(arr, k, arr.size(), INF);
}

int tab(vi arr, int K) {
    int n = arr.size();
    vvvi dp(K + 1, vvi(n + 1, vi(n + 1)));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (k == 0) dp[k][i][j] = 0;
                else if (i == 0) dp[k][i][j] = INF;
                else if (j == 0) dp[k][i][j] = min(dp[k - 1][i - 1][i] + arr[i - 1], dp[k][i - 1][j]);
                else if (arr[i - 1] <= arr[j - 1]) dp[k][i][j] = min(dp[k - 1][i - 1][i] + arr[i - 1], dp[k][i - 1][j]);
                else dp[k][i][j] = dp[k][i - 1][j];
            }
        }
    }
    return dp[K][n][n];
}

int rec2(vi arr, int k, int n, int prev) {
    if (k == 0) return 0;
    if (n == 0) return INF;
    if (arr[n - 1] <= arr[prev - 1]) return min(rec2(arr, k - 1, n - 1, n) + arr[n - 1], rec2(arr, k, n - 1, prev));
    return rec2(arr, k, n - 1, prev);
}

int rec2(vi arr, int k) {
    int ans = INF;
    for (int i = 1; i <= arr.size(); ++i) {
        ans = min(ans, rec2(arr, k - 1, i - 1, i) + arr[i - 1]);
    }
    return ans;
}

int tab2(vi arr, int K) {
    int n = arr.size();
    vvvi dp(K + 1, vvi(n + 1, vi(n + 1)));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (k == 0) dp[k][i][j] = 0;
                else if (i == 0) dp[k][i][j] = INF;
                else if (arr[i - 1] <= arr[j - 1]) dp[k][i][j] = min(dp[k - 1][i - 1][i] + arr[i - 1], dp[k][i - 1][j]);
                else dp[k][i][j] = dp[k][i - 1][j];
            }
        }
    }
    int ans = INF;
    for (int i = 1; i <= n; ++i) {
        ans = min(ans, dp[K - 1][i - 1][i] + arr[i - 1]);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k1 = 3;
    vi arr2 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k2 = 4;
    vi arr3 = {58, 12, 11, 12, 82, 30, 20, 77, 16, 86}; int k3 = 5;

    cout << naive(arr1, k1) << '\n'; // 39
    cout << naive(arr2, k2) << '\n'; // 120
    cout << naive(arr3, k3) << '\n'; // 206
    cout << '\n';
    cout << rec(arr1, k1) << '\n'; // 39
    cout << rec(arr2, k2) << '\n'; // 120
    cout << rec(arr3, k3) << '\n'; // 206
    cout << '\n';
    cout << tab(arr1, k1) << '\n'; // 39
    cout << tab(arr2, k2) << '\n'; // 120
    cout << tab(arr3, k3) << '\n'; // 206
    cout << '\n';
    cout << rec2(arr1, k1) << '\n'; // 39
    cout << rec2(arr2, k2) << '\n'; // 120
    cout << rec2(arr3, k3) << '\n'; // 206
    cout << '\n';
    cout << tab2(arr1, k1) << '\n'; // 39
    cout << tab2(arr2, k2) << '\n'; // 120
    cout << tab2(arr3, k3) << '\n'; // 206
}
