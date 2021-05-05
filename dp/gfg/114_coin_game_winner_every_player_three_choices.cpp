#include "../../template.hpp"

int rec(int n, int x, int y, int isa) {
    if (n == 0 and isa) return 1;
    if (n <= 0) return 0;
    return rec(n - 1, x, y, !isa) or rec(n - x, x, y, !isa) or rec(n - y, x, y, !isa);
}

int rec(int n, int x, int y) {
    return rec(n - 1, x, y, 1) or rec(n - x, x, y, 1) or rec(n - y, x, y, 1);
}

int tab(int n, int x, int y) {
    vvi dp(n + 1, vi(2));
    for (int i = 0; i <= n; ++i) {
        for (int j : {0, 1}) {
            if (i == 0 and j == 1) {
                dp[i][j] = 1;
            }
            else if (i == 0) {
                dp[i][j] = 0;
            }
            else {
                dp[i][j] = dp[i - 1][!j];
                if (i >= x and not dp[i][j]) dp[i][j] = dp[i - x][!j];
                if (i >= y and not dp[i][j]) dp[i][j] = dp[i - y][!j];
            }
        }
    }
    if (dp[n - 1][1]) return 1;
    if (n >= x and dp[n - x][1]) return 1;
    if (n >= y and dp[n - y][1]) return 1;
    return 0;
}

int main() { // TimeMeasure _; __x();
    int n1 = 5, x1 = 3, y1 = 4;
    int n2 = 2, x2 = 3, y2 = 4;
    cout << rec(n1, x1, y1) << endl; // A
    cout << rec(n2, x2, y2) << endl; // B
    cout << tab(n1, x1, y1) << endl; // A
    cout << tab(n2, x2, y2) << endl; // B
}
