#include "../../template.hpp"

int naive(vi& arr1, vi& arr2, int m, int n) {
    if (m == 0 or n == 0) return 0;
    if (arr1[m - 1] == arr2[n - 1]) return naive(arr1, arr2, m - 1, n - 1) + 1;
    return max(naive(arr1, arr2, m - 1, n), naive(arr1, arr2, m, n - 1));
}

int naive(vi& arr1, vi& arr2, int k) {
    int m = arr1.size(), n = arr2.size();
    int lcs = naive(arr1, arr2, m, n);
    int minlen = min(m, n);
    return (minlen - lcs < k ? minlen - lcs : k) + lcs;
}

int tab_naive(vi& arr1, vi& arr2, int k) {
    int m = arr1.size(), n = arr2.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
            if (i == 0 or j == 0) dp[i][j] = 0;
            else if (arr1[i - 1] == arr2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    int lcs = dp[m][n];
    int minlen = min(m, n);
    return (minlen - lcs < k ? minlen - lcs : k) + lcs;
}

int tab_straight(vi& arr1, vi& arr2, int K) {
    int m = arr1.size(), n = arr2.size();
    vvvi dp(K + 1, vvi(m + 1, vi(n + 1)));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 or j == 0) {
                    dp[k][i][j] = 0;
                }
                else if (arr1[i - 1] == arr2[j - 1]) {
                    dp[k][i][j] = 1 + dp[k][i - 1][j - 1];
                }
                else {
                    dp[k][i][j] = max({k > 0 ? dp[k - 1][i - 1][j - 1] + 1 : 0,
                                       dp[k][i - 1][j],
                                       dp[k][i][j - 1]});
                }
            }
        }
    }
    return dp[K][m][n];
}

int tab_elems(vi& arr1, vi& arr2, int K) {
    int m = arr1.size(), n = arr2.size();
    vvvi dp(K + 1, vvi(m + 1, vi(n + 1)));
    vvvvi prev(K + 1, vvvi(m + 1, vvi(n + 1)));
    for (int k = 0; k <= K; ++k) {
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if (i == 0 or j == 0) {
                    dp[k][i][j] = 0;
                }
                else if (arr1[i - 1] == arr2[j - 1]) {
                    dp[k][i][j] = 1 + dp[k][i - 1][j - 1];
                    prev[k][i][j] = {k, i - 1, j - 1, 1};
                }
                else {
                    dp[k][i][j] = max({k > 0 ? dp[k - 1][i - 1][j - 1] + 1 : 0,
                                       dp[k][i - 1][j],
                                       dp[k][i][j - 1]});
                    if (k > 0 and dp[k][i][j] == dp[k - 1][i - 1][j - 1] + 1) {
                        prev[k][i][j] = {k - 1, i - 1, j - 1, 2};
                    }
                    else if (dp[k][i][j] == dp[k][i - 1][j]) {
                        prev[k][i][j] = {k, i - 1, j, 0};
                    }
                    else {
                        prev[k][i][j] = {k, i, j - 1, 0};
                    }
                }
            }
        }
    }
    for (vi at = prev[K][m][n]; not at.empty(); at = prev[at[0]][at[1]][at[2]]) {
        if (at[3] == 1) {
            cout << arr1[at[1]] << ' ';
        }
        else if (at[3] == 2) {
            cout << '(' << arr1[at[1]] << "->" << arr2[at[2]] << ')' << ' ';
        }
    }
    cout << '\n';
    return dp[K][m][n];
}

int main() { TimeMeasure _; __x();
    vi arr11 = {8, 3}, arr12 = {1, 3}; int k1 = 1;
    vi arr21 = {1, 2, 3, 4, 5}, arr22 = {5, 3, 1, 4, 2}; int k2 = 1;
    vi arr31 = {1, 2, 3, 4}, arr32 = {5, 1, 2, 3, 8}; int k3 = 1;

    cout << naive(arr11, arr12, k1) << endl; // 2
    cout << naive(arr21, arr22, k2) << endl; // 3
    cout << naive(arr31, arr32, k3) << endl; // 4
    cout << '\n';
    cout << tab_naive(arr11, arr12, k1) << endl; // 2
    cout << tab_naive(arr21, arr22, k2) << endl; // 3
    cout << tab_naive(arr31, arr32, k3) << endl; // 4
    cout << '\n';
    cout << tab_straight(arr11, arr12, k1) << endl; // 2
    cout << tab_straight(arr21, arr22, k2) << endl; // 3
    cout << tab_straight(arr31, arr32, k3) << endl; // 4
    cout << '\n';
    cout << tab_elems(arr11, arr12, k1) << endl; // 2
    cout << tab_elems(arr21, arr22, k2) << endl; // 3
    cout << tab_elems(arr31, arr32, k3) << endl; // 4
}
