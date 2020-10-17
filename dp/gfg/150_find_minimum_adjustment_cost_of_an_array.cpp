#include "../../template.hpp"

static const int MAX = 100;

int tab(const vi& arr, const int target) {
    int n = arr.size();
    vvi dp(n, vi(MAX + 1, INF));
    for (int j = 1; j <= MAX; ++j) { // adjust first element to j
        int cost_to_adjust = abs(j - arr[0]);
        dp[0][j] = cost_to_adjust;
    }
    for (int i = 1; i < n; ++i) { // adjust every element
        for (int j = 1; j <= MAX; ++j) { // to a value j
            for (int k = 1; k <= MAX; ++k) { // check if prev element adj to k
                if (abs(j - k) <= target) { // and their adjustement is ok
                    int cost_to_adjust = abs(j - arr[i]);
                    int cost_to_adjust_prev = dp[i - 1][k];
                    int diff = cost_to_adjust + cost_to_adjust_prev;
                    dp[i][j] = min(dp[i][j], diff);
                }
            }
        }
    }
    int res = INF;
    for (int k = 1; k <= MAX; ++k) {
        res = min(res, dp[n - 1][k]);
    }
    return res;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 3, 0, 3}; int target1 = 1;
    vi arr2 = {2, 3, 2, 3}; int target2 = 1;
    vi arr3 = {55, 77, 52, 61, 39, 6, 25, 60, 49, 47}; int target3 = 10;
    cout << tab(arr1, target1) << endl;
    cout << tab(arr2, target2) << endl;
    cout << tab(arr3, target3) << endl;
}
