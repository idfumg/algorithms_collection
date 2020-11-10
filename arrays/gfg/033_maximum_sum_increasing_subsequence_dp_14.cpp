#include "../../template.hpp"

int tab(vi arr) {
    int n = arr.size();
    vi dp = arr;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
            }
        }
    }
    return max(dp);
}

int main() { TimeMeasure _;
    cout << tab({1, 101, 2, 3, 100, 4, 5}) << '\n'; // 106
}
