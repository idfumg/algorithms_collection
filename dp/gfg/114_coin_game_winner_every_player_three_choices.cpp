#include "../../template.hpp"

bool rec(int n, int x, int y, bool wasA) {
    if (n == 0 and wasA) return true;
    if (n <= 0) return false;
    return
        rec(n - 1, x, y, not wasA) or
        rec(n - x, x, y, not wasA) or
        rec(n - y, x, y, not wasA);
}

char rec(int n, int x, int y) {
    return rec(n, x, y, false) ? 'A' : 'B';
}

char tab(int n, int x, int y) {
    vvi dp(n + 1, vi(2));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int wasA : {0, 1}) {
            dp[i][wasA] =
                (i >= 1 ? dp[i - 1][!wasA] : 0) or
                (i >= x ? dp[i - x][!wasA] : 0) or
                (i >= y ? dp[i - y][!wasA] : 0);
        }
    }
    return dp[n][1] == 1 ? 'A' : 'B';
}

int main() { TimeMeasure _; __x();
    int n1 = 5, x1 = 3, y1 = 4;
    int n2 = 2, x2 = 3, y2 = 4;
    cout << rec(n1, x1, y1) << endl; // A
    cout << rec(n2, x2, y2) << endl; // B
    cout << tab(n1, x1, y1) << endl; // A
    cout << tab(n2, x2, y2) << endl; // B
}
