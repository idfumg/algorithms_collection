#include "../../template.hpp"

int rec(vi arr, int number, int maxsum, int i, int current) {
    int n = arr.size();

    if (current < 0 or current > maxsum) {
        return -INF;
    }

    if (i > n) {
        return current;
    }

    if (i == 0) {
        return rec(arr, number, maxsum, i + 1, number);
    }

    return max(rec(arr, number, maxsum, i + 1, current + arr[i - 1]),
               rec(arr, number, maxsum, i + 1, current - arr[i - 1]));
}

int rec(vi arr, int number, int maxsum) {
    return rec(arr, number, maxsum, 0, 0);
}

int tab(vi arr, int number, int maxsum) {
    int n = arr.size();
    vvb dp(n + 1, vb(maxsum + 1));

    if (number - arr[0] >= 0) {
        dp[1][number - arr[0]] = true;
    }

    if (number + arr[0] <= maxsum) {
        dp[1][number + arr[0]] = true;
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= maxsum; ++j) {
            if (j + arr[i - 1] <= maxsum) {
                dp[i][j] = dp[i][j] or dp[i - 1][j + arr[i - 1]];
            }
            if (j - arr[i - 1] >= 0) {
                dp[i][j] = dp[i][j] or dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    for (int i = maxsum; i >= 0; --i) {
        if (dp[n][i]) {
            return i;
        }
    }

    return dp[0][0];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {2, 1, 7}; int n1 = 3, sum1 = 7;
    vi arr2 = {3, 10, 6, 4, 5}; int n2 = 1, sum2 = 15;
    cout << rec(arr1, n1, sum1) << endl; // 7
    cout << rec(arr2, n2, sum2) << endl; // 9
    cout << '\n';
    cout << tab(arr1, n1, sum1) << endl; // 7
    cout << tab(arr2, n2, sum2) << endl; // 9
}
