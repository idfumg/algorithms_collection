#include "../../template.hpp"

bool isValid(vvi& arr, int i, int j) {
    return not (i < 0 or j < 0 or i >= arr.size() or j >= arr[0].size());
}

vvi tab(vvi& arr) {
    int m = arr.size(), n = arr[0].size();
    vvi dp(m, vi(n));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (isValid(arr, i - 1, j)) dp[i][j] += dp[i - 1][j];
            if (isValid(arr, i, j - 1)) dp[i][j] += dp[i][j - 1];
            if (isValid(arr, i - 1, j - 1)) dp[i][j] -= dp[i - 1][j - 1];
            dp[i][j] += arr[i][j];
        }
    }
    return dp;
}

int main() { TimeMeasure _; __x();
    vvi arr1 = {{10, 20, 30},
                {5, 10, 20},
                {2, 4, 6}};
    vvi arr2 = {{1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1}};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
}
