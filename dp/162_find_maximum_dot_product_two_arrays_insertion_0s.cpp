#include "../template.hpp"

int tab(vi& arr1, vi& arr2) {
    int m = arr1.size(), n = arr2.size();
    vvi dp(m + 1, vi(n + 1));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = max({dp[i - 1][j - 1] + arr1[i - 1] * arr2[j - 1],
                            dp[i - 1][j]});
        }
    }
    return dp[m][n];
}

int main() { TimeMeasure _; __x();
    vi arr11 = {2, 3, 1, 7, 8}, arr12 = {3, 6, 7};
    vi arr21 = {1, 2, 3, 6, 1, 4}, arr22 = {4, 5, 1};
    cout << tab(arr11, arr12) << endl;
    cout << tab(arr21, arr22) << endl;
}
