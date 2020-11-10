#include "../../template.hpp"

int rec(vi arr, int i) {
    int n = arr.size();

    if (i >= n) {
        return 0;
    }

    int mini = INF;
    for (int j = i + 1; j <= i + arr[i - 1]; ++j) {
        mini = min(mini, rec(arr, j) + 1);
    }
    return mini;
}

int rec(vi arr) {
    return rec(arr, 1);
}

int tab(vi arr) {
    int n = arr.size();
    vi dp(n + 1);
    for (int i = n - 1; i >= 1; --i) {
        int mini = INF;
        for (int j = i + 1; j <= min(n, i + arr[i - 1]); ++j) {
            mini = min(mini, dp[j] + 1);
        }
        dp[i] = mini;
    }
    return dp[1];
}

int main() { TimeMeasure _;
    cout << rec({1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}) << '\n'; // 3
    cout << rec({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}) << '\n'; // 10
    cout << tab({0, 1, 1, 1, 1}) << '\n'; // 10
    cout << '\n';
    cout << tab({1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}) << '\n'; // 3
    cout << tab({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}) << '\n'; // 10
    cout << tab({0, 1, 1, 1, 1}) << '\n'; // 10
}
