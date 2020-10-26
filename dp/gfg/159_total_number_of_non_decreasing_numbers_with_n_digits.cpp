#include "../../template.hpp"

bool IsIncreasing(int n) {
    int prev = n % 10;
    n /= 10;
    while (n > 0) {
        if (prev < n % 10) {
            return false;
        }
        prev = n % 10;
        n /= 10;
    }
    return true;
}

int naive(int n) {
    int count = 0, to = pow(10, n) - 1;
    for (int i = 0; i <= to; ++i) {
        if (IsIncreasing(i)) {
            ++count;
        }
    }
    return count;
}

int rec(int n, int digit, int prev) {
    if (digit < prev or digit > 9) {
        return 0;
    }
    if (n == 0) {
        return 1;
    }
    return
        rec(n - 1, digit, digit) +
        rec(n, digit + 1, digit);
}

int rec(int n) {
    return rec(n, 0, 0);
}

int tab(int n) {
    vvvi dp(n + 1, vvi(11, vi(11)));
    for (int i = 0; i <= n; ++i) {
        for (int j = 9; j >= 0; --j) {
            for (int k = 9; k >= 0; --k) {
                if (j < k) {
                    dp[i][j][k] = 0;
                }
                else if (i == 0) {
                    dp[i][j][k] = 1;
                }
                else {
                    dp[i][j][k] = dp[i - 1][j][j] + dp[i][j + 1][j];
                }
            }
        }
    }
    return dp[n][0][0];
}

int main() { TimeMeasure _; __x();
    cout << naive(1) << endl; // 10
    cout << naive(2) << endl; // 55
    cout << naive(3) << endl; // 220
    cout << '\n';
    cout << rec(1) << endl;
    cout << rec(2) << endl;
    cout << rec(3) << endl;
    cout << '\n';
    cout << tab(1) << endl;
    cout << tab(2) << endl;
    cout << tab(3) << endl;
}
