#include "../../template.hpp"

int NumOfSubsetsWithGcd_(vi arr, int g) {
    int n = arr.size();
    vvi dp(n + 1, vi(n + 1));

    for (int j = 1; j <= n; ++j) {
        dp[1][j] = arr[j - 1] == g;
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (gcd(arr[j - 1], arr[i - 1]) == g) {
                dp[2][i] += 1;
            }
        }
    }

    for (int k = 3; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j < i; ++j) {
                if (dp[k - 1][j] > 0 and gcd(arr[j - 1], arr[i - 1]) == g) {
                    dp[k][i] += dp[k - 1][j];
                }
            }
        }
    }

    int ans = 0;
    for (int k = 1; k <= n; ++k) {
        for (int j = 1; j <= n; ++j) {
            ans += dp[k][j];
        }
    }
    return ans;
}

int NumOfSubsetsWithGcd(vi arr, vi gcds) {
    int count = 0;
    for (int g : gcds) {
        count += NumOfSubsetsWithGcd_(arr, g);
    }
    return count;
}

int main() { TimeMeasure _; __x();
    cout << NumOfSubsetsWithGcd({2, 3, 4}, {2, 3}) << endl; // 3 (2 + 1)
    cout << NumOfSubsetsWithGcd({6, 3, 9, 2}, {3, 2}) << endl; // 7 (5 + 2)
}
