#include "../template.hpp"

bool rec(int n, int x, int y, bool isA) {
    if (n == 1 or n == x or n == y) return isA;
    if (n < 0) return false;
    return
        rec(n - 1, x, y, !isA) or
        rec(n - x, x, y, !isA) or
        rec(n - y, x, y, !isA);
}

char rec(int n, int x, int y) {
    return rec(n, x, y, true) ? 'A' : 'B';
}

char tab(int n, int x, int y) {
    vb dp(n + 1);
    dp[0] = false;
    dp[1] = true;

    for (int i = 2; i <= n; ++i) {
        if (i - 1 >= 0 && !dp[i - 1]) {
            dp[i] = true;
        }
        else if (i - x >= 0 && !dp[i - x]) {
            dp[i] = true;
        }
        else if (i - y >= 0 && !dp[i - y]) {
            dp[i] = true;
        }
    }

    return dp[n] ? 'A' : 'B';
}

char tab2(int n, int x, int y) {
    vvb dp(n + 1, vb(2));

    for (int i = 1; i <= n; ++i) {
        for (bool isA : {true, false}) {
            if (i - 1 == 0 && isA) {
                dp[i][isA] = true;
            }
            else if (i - x == 0 && isA) {
                dp[i][isA] = true;
            }
            else if (i - y == 0 && isA) {
                dp[i][isA] = true;
            }
            else if (i - 1 >= 0 && dp[i - 1][!isA]) {
                dp[i][isA] = true;
            }
            else if (i - x >= 0 && dp[i - x][!isA]) {
                dp[i][isA] = true;
            }
            else if (i - y >= 0 && dp[i - y][!isA]) {
                dp[i][isA] = true;
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
    cout << tab2(n1, x1, y1) << endl;
    cout << tab2(n2, x2, y2) << endl;
}
