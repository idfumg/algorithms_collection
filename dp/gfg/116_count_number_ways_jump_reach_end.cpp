#include "../../template.hpp"

vi tab(vi& arr) {
    int n = arr.size();
    vi dp(n);
    dp[n - 1] = 1;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = min(i + arr[i], n - 1); j > i; --j) {
            dp[i] += dp[j] == -1 ? 0 : dp[j];
        }
        if (dp[i] == 0) {
            dp[i] = -1;
            continue;
        }
    }
    dp[n - 1] = 0;
    return dp;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {3, 2, 0, 1};
    vi arr2 = {1, 3, 5, 8, 9, 1, 0, 7, 6, 8, 9};
    cout << tab(arr1) << endl; // 2 1 -1 0
    cout << tab(arr2) << endl; // 52 52 28 16 8 -1 -1 4 2 1 0
}
