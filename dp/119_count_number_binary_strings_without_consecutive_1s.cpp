#include "../../template.hpp"

int with1(int n);

int with0(int n) {
    if (n == 1) return 1;
    return with0(n - 1) + with1(n - 1);
}

int with1(int n) {
    if (n == 1) return 1;
    return with0(n - 1);
}

int rec(int n) {
    return with0(n) + with1(n);
}

int tab(int n) {
    vi with0(n), with1(n);
    with0[0] = with1[0] = 1;
    for (int i = 1; i < n; ++i) {
        with0[i] = with0[i - 1] + with1[i - 1];
        with1[i] = with0[i - 1];
    }
    return with0[n - 1] + with1[n - 1];
}

int opt(int n) {
    vi with0(2), with1(2);
    with0[0] = with1[0] = 1;
    int idx = 0;
    for (int i = 1; i < n; ++i) {
        idx = i & 1;
        with0[idx] = with0[1 - idx] + with1[1 - idx];
        with1[idx] = with0[1 - idx];
    }
    return with0[idx] + with1[idx];
}

int rec2(int n, int prev) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    int count = 0;
    for (int i : {0, 1}) {
        if (prev == 1 and i == 1) continue;
        count += rec2(n - 1, i);
    }
    return count;
}

int rec2(int n) {
    if (n == 0) return 0;
    int count = 0;
    for (int i : {0, 1}) {
        count += rec2(n - 1, i);
    }
    return count;
}

int tab2(int n) {
    if (n == 0) return 0;
    vvi dp(n + 1, vi(2));
    for (int i = 0; i <= n; ++i) {
        for (int j : {0, 1}) {
            if (i == 0) {
                dp[i][j] = 1;
            }
            else {
                for (int k : {0, 1}) {
                    if (j == 1 and k == 1) continue;
                    dp[i][j] += dp[i - 1][k];
                }
            }
        }

    }
    return dp[n - 1][0] + dp[n - 1][1];
}

int main() { TimeMeasure _; __x();
    cout << rec(2) << endl;
    cout << rec(3) << endl;
    cout << tab(2) << endl;
    cout << tab(3) << endl;
    cout << opt(2) << endl;
    cout << opt(3) << endl;
    cout << rec2(2) << endl;
    cout << rec2(3) << endl;
    cout << tab2(2) << endl;
    cout << tab2(3) << endl;
}
