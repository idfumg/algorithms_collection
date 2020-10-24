#include "../../template.hpp"

bool IsStepping(int n) {
    int prev = INF;
    while (n > 0) {
        int current = n % 10;
        if (prev != INF) {
            if (abs(prev - current) != 1) {
                return false;
            }
        }
        prev = current;
        n /= 10;
    }
    return true;
}

int naive(int n) {
    int ans = 0;
    int start = n == 1 ? 0 : pow(10, n - 1);
    int stop = pow(10, n) - 1;
    for (int i = start; i <= stop; ++i) {
        if (IsStepping(i)) {
            ++ans;
        }
    }
    return ans;
}

int tab(int num) {
    int n = pow(10, num) - 1;
    int from = num == 1 ? 0 : pow(10, num - 1);
    vi dp(n + 1);

    for (int i = 0; i <= n; ++i) {
        if (i < 10) {
            dp[i] = 1;
        }
        else {
            int prev = (i / 10) % 10;
            int current = i % 10;
            dp[i] = dp[i / 10] and abs(prev - current) == 1;
        }
    }

    return accumulate(dp.begin() + from, dp.end(), 0);
}

int rec(int num, int current) {
    if (num == 0) {
        return 1;
    }
    int ans = 0;
    for (int i = 0; i <= 9; ++i) {
        if (abs((current % 10) - i) == 1) {
            ans += rec(num - 1, current * 10 + i);
        }
    }
    return ans;
}

int rec(int num) {
    if (num == 1) {
        return 10;
    }
    int ans = 0;
    for (int i = 1; i <= 9; ++i) {
        ans += rec(num - 1, i);
    }
    return ans;
}

int rec2(int num, int prev) {
    if (num == 0) {
        return 1;
    }
    int ans = 0;
    for (int i = (prev == -1 ? 1 : 0); i <= 9; ++i) {
        if (prev == -1 or abs(prev - i) == 1) {
            ans += rec2(num - 1, i);
        }
    }
    return ans;
}

int rec2(int num) {
    if (num == 1) {
        return 10;
    }
    return rec2(num, -1);
}

int tab2(int num) {
    if (num == 1) {
        return 10;
    }

    vvi dp(num + 1, vi(10));

    for (int j = 1; j <= 9; ++j) {
        dp[1][j] = 1;
    }

    for (int i = 1; i <= num; ++i) {
        for (int j = 0; j <= 9; ++j) {
            for (int k = 0; k <= 9; ++k) {
                if (abs(j - k) == 1) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }
    }

    return accumulate(dp[num].begin(), dp[num].end(), 0);
}

int main() { TimeMeasure _; __x();
    cout << naive(1) << endl; // 10
    cout << naive(2) << endl; // 17
    cout << naive(3) << endl; // 32
    cout << '\n';
    cout << tab(1) << endl;
    cout << tab(2) << endl;
    cout << tab(3) << endl;
    cout << '\n';
    cout << rec(1) << endl;
    cout << rec(2) << endl;
    cout << rec(3) << endl;
    cout << '\n';
    cout << rec2(1) << endl;
    cout << rec2(2) << endl;
    cout << rec2(3) << endl;
    cout << '\n';
    cout << tab2(1) << endl;
    cout << tab2(2) << endl;
    cout << tab2(3) << endl;
}
