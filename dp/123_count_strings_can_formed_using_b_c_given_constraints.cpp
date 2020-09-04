#include "../../template.hpp"

int rec(int n, int b, int c) {
    if (b < 0 or c < 0) return 0;
    if (n == 0) return 1;

    return rec(n - 1, b, c) + rec(n - 1, b - 1, c) + rec(n - 1, b, c - 1);
}

int rec(int n) {
    return rec(n, 1, 2);
}

int tab(int n) {
    int b = 1, c = 2;
    vvvi dp(n + 1, vvi(b + 1, vi(c + 1)));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; ++k) {
                if (i == 0) {
                    dp[i][j][k] = 1;
                }
                else {
                    dp[i][j][k] =
                        dp[i - 1][j][k] +
                        (j > 0 ? dp[i - 1][j - 1][k] : 0) +
                        (k > 0 ? dp[i - 1][j][k - 1] : 0);
                }

            }
        }
    }
    return dp[n][b][c];
}

int main() { TimeMeasure _; __x();
    int n1 = 3;
    int n2 = 4;
    cout << rec(n1) << endl;
    cout << rec(n2) << endl;
    cout << tab(n1) << endl;
    cout << tab(n2) << endl;
}
