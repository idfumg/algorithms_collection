#include "../template.hpp"

bool IsStepping(int n) {
    int prev = n % 10;
    n /= 10;
    while (n > 0) {
        int current = n % 10;
        if (abs(prev - current) != 1) {
            return false;
        }
        prev = current;
        n /= 10;
    }
    return true;
}

int naive(int n) {
    int from = n == 1 ? 0 : pow(10, n) / 10;
    int to = pow(10, n) - 1;
    int count = 0;
    for (int i = from; i <= to; ++i) {
        if (IsStepping(i)) {
            ++count;
        }
    }
    return count;
}

int rec(int prev, int k) {
    if (k == 0) return 1;
    int count = 0;
    for (int i = 0; i <= 9; ++i) {
        if (abs(prev - i) == 1) {
            count += rec(i, k - 1);
        }
    }
    return count;
}

int rec(int k) {
    int count = k == 1 ? 1 : 0;
    for (int i = 1; i <= 9; ++i) {
        count += rec(i, k - 1);
    }
    return count;
}

int tab1(int k) {
    int n = pow(10, k) - 1;
    vb dp(n + 1);
    for (int i = 0; i <= n; ++i) {
        if (i < 10) {
            dp[i] = true;
        }
        else {
            dp[i] = dp[i / 10] and abs(i % 10 - (i / 10) % 10) == 1;
        }
    }
    int from = k == 1 ? 0 : pow(10, k) / 10, count = 0;
    for (int i = from; i <= n; ++i) {
        count += dp[i];
    }
    return count;
}

int tab2(int n) {
    vvi dp(n + 1, vi(10));
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                if (i == 1) {
                    dp[i][j] = 1;
                }
                else if (abs(j - k) == 1) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }
    return accumulate(dp[n].begin(), dp[n].end(), 0) - dp[n][0];
}

int main() { TimeMeasure _; __x();
    cout << naive(1) << endl;
    cout << naive(2) << endl;
    cout << naive(3) << endl;
    cout << '\n';
    cout << rec(1) << endl;
    cout << rec(2) << endl;
    cout << rec(3) << endl;
    cout << '\n';
    cout << tab1(1) << endl;
    cout << tab1(2) << endl;
    cout << tab1(3) << endl;
    cout << '\n';
    cout << tab2(1) << endl;
    cout << tab2(2) << endl;
    cout << tab2(3) << endl;
}
