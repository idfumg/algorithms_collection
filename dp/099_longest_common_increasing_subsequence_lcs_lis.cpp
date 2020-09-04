#include "../template.hpp"

vi get_lcs(const vi& arr1, const vi& arr2) {
    int m = arr1.size(), n = arr2.size();
    vvi dp(m + 1, vi(n + 1)); // longest common when sizes are i and j
    vvvi prev(m + 1, vvi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (arr1[i - 1] == arr2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                prev[i][j] = {i - 1, j - 1, 1};
            }
            else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    prev[i][j] = {i - 1, j, 0};
                    dp[i][j] = dp[i - 1][j];
                }
                else {
                    prev[i][j] = {i, j - 1, 0};
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }
    vi lcs(dp[m][n]);
    int pos = lcs.size() - 1;
    for (vi at = prev[m][n]; pos >= 0; at = prev[at[0]][at[1]]) {
        if (at[2] == 1) {
            lcs[pos--] = arr1[at[0]];
        }
    }
    return lcs;
}

vi get_lis(const vi& arr) {
    int n = arr.size(), maxsize = 0, maxpos = 0;
    vi dp(n, 1), prev(n, -1);
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (maxsize < dp[i]) {
                maxsize = dp[i];
                maxpos = i;
            }
        }
    }
    vi lis(maxsize);
    int pos = lis.size() - 1;
    for (int at = maxpos; pos >= 0; at = prev[at]) {
        lis[pos--] = arr[at];
    }
    return lis;
}

vi tab(const vi& arr1, const vi& arr2) {
    const vi lcs = get_lcs(arr1, arr2);
    const vi lis = get_lis(lcs);
    return lis;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {3, 4, 9, 1};
    vi arr2 = {5, 3, 8, 9, 10, 2, 1};
    cout << tab(arr1, arr2) << endl;
}
