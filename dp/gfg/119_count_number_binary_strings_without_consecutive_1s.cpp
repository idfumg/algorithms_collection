#include "../../template.hpp"

int rec(int n, int prev) {
    if (n == 0) return 1;
    if (prev == 0) return rec(n - 1, 0) + rec(n - 1, 1);
    return rec(n - 1, 0);
}

int rec(int n) {
    return rec(n - 1, 0) + rec(n - 1, 1);
}

int tab(int n) {
    vvi dp(n + 1, vi(2));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= 1; ++j) {
            if (i == 0) dp[i][j] = 1;
            else if (j == 0) dp[i][j] = dp[i - 1][0] + dp[i - 1][1];
            else dp[i][j] = dp[i - 1][0];
        }
    }
    return dp[n - 1][0] + dp[n - 1][1];
}

int opt(int n) {
    vvi dp(2, vi(2));
    int idx = 0;
    for (int i = 0; i <= n; ++i) {
        idx = i & 1;
        for (int j = 0; j <= 1; ++j) {
            if (i == 0) dp[idx][j] = 1;
            else if (j == 0) dp[idx][j] = dp[1 - idx][0] + dp[1 - idx][1];
            else dp[idx][j] = dp[1 - idx][0];
        }
    }
    return dp[1 - idx][0] + dp[1 - idx][1];
}

int with1(int n);

int with0(int n) {
    if (n == 0) return 1;
    return with0(n - 1) + with1(n - 1);
}
int with1(int n) {
    if (n == 0) return 1;
    return with0(n - 1);
}

int rec2(int n) {
    return with0(n - 1) + with1(n - 1);
}

int tab2(int n) {
    vi w0(n + 1), w1(n + 1);
    w0[0] = w1[0] = 1;
    for (int i = 1; i < n; ++i) {
        w1[i] = w0[i - 1];
        w0[i] = w0[i - 1] + w1[i - 1];
    }
    return w0[n - 1] + w1[n - 1];
}

int main() { TimeMeasure _; __x();
    cout << rec(2) << endl; // 3
    cout << rec(3) << endl; // 5
    cout << endl;
    cout << tab(2) << endl;
    cout << tab(3) << endl;
    cout << endl;
    cout << opt(2) << endl;
    cout << opt(3) << endl;
    cout << endl;
    cout << rec2(2) << endl;
    cout << rec2(3) << endl;
    cout << endl;
    cout << tab2(2) << endl;
    cout << tab2(3) << endl;
}
