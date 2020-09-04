#include "../../template.hpp"

bool rec(int n, int x, int y, bool isA) {
    if (n == 0) return isA;
    if (n < 0) return false;
    return
        rec(n - x, x, y, !isA) or
        rec(n - y, x, y, !isA) or
        rec(n - 1, x, y, !isA);
}

char rec(int n, int x, int y) {
    return rec(n, x, y, false) ? 'A' : 'B';
}

char tab(int n, int x, int y) {
    vvb dp(n + 1, vb(2));
    for (int i = 0; i <= n; ++i) {
        for (bool isA : {false, true}) {
            if (i == 0) {
                dp[i][isA] = !isA;
            }
            else {
                if (i >= x && dp[i - x][!isA]) dp[i][isA] = true;
                else if (i >= y && dp[i - y][!isA]) dp[i][isA] = true;
                else if (i >= 1 && dp[i - 1][!isA]) dp[i][isA] = true;
            }
        }
    }
    return dp[n][true] ? 'A' : 'B';
}

int main() { TimeMeasure _; __x();
    int n1 = 5, x1 = 3, y1 = 4;
    int n2 = 2, x2 = 3, y2 = 4;
    cout << rec(n1, x1, y1) << endl;
    cout << rec(n2, x2, y2) << endl;
    cout << tab(n1, x1, y1) << endl;
    cout << tab(n2, x2, y2) << endl;
}
