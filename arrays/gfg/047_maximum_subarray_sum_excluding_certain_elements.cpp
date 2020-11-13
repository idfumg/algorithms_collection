#include "../../template.hpp"

void MaxSubArraySumExcludingSecondElements(vi a, vi b) {
    unordered_set<int> tab;
    for (int value : b) {
        tab.insert(value);
    }
    int m = a.size();
    vi dp(m);
    dp[0] = tab.count(a[0]) ? 0 : a[0];
    for (int i = 1; i < m; ++i) {
        if (tab.count(a[i])) {
            dp[i] = 0;
        }
        else {
            dp[i] = dp[i - 1] + a[i];
        }
    }
    cout << max(dp) << '\n';
}

int main() { TimeMeasure _;
    MaxSubArraySumExcludingSecondElements({1, 7, -10, 6, 2}, {5, 6, 7, 1}); // 2
    MaxSubArraySumExcludingSecondElements({3, 4, 5, -4, 6}, {1, 8, 5}); // 7
}
