#include "../../template.hpp"

// dp[i][j] - how many elements we need to remove so arr[i]*2 > arr[j] in this diapason?

int tab(vi arr) {
    int n = arr.size();
    vvvi dpmin(n + 2, vvi(n + 2, vi{INF, -INF}));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) continue;
            dpmin[i][j] = {
                min({dpmin[i + 1][j][0], arr[i - 1], arr[j - 1]}),
                max({dpmin[i][j - 1][1], arr[i - 1], arr[j - 1]})
            };
        }
    }
    vvi dp(n + 2, vi(n + 2, INF));
    for (int i = n; i >= 1; --i) {
        for (int j = 1; j <= n; ++j) {
            if (i > j) continue;
            if (dpmin[i][j][0] * 2 <= dpmin[i][j][1]) {
                dp[i][j] = min({dp[i + 1][j] + 1, dp[i][j - 1] + 1});
            }
            else {
                dp[i][j] = 0;
            }
        }
    }
    return dp[1][n];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 5, 100, 9, 10, 11, 12, 15, 200}; // 4
    vi arr2 = {4, 7, 5, 6}; // 0
    vi arr3 = {20, 7, 5, 6}; // 1
    vi arr4 = {20, 4, 1, 3}; // 3

    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
    cout << tab(arr4) << endl;
}
