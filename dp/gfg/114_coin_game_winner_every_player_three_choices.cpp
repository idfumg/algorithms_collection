#include "../../template.hpp"

bool rec(int n, int x, int y, int isa) {
    if (n == 0 and isa) return true;
    else if (n <= 0) return false;
    for (int coins : {1, x, y}) {
        if (rec(n - coins, x, y, !isa)) {
            return true;
        }
    }
    return false;
}

char rec(int n, int x, int y) {
    for (int coins : {1, x, y}) {
        if (rec(n - coins, x, y, true)) {
            return 'A';
        }
    }
    return 'B';
}

char tab(int n, int x, int y) {
    vvi dp(n + 1, vi(2));
    for (int i = 0; i <= n; ++i) {
        for (int isa : {0, 1}) {
            if (i == 0 and isa) {
                dp[i][isa] = 1;
            }
            else if (i == 0) {
                dp[i][isa] = 0;
            }
            else {
                for (int coins : {1, x, y}) {
                    if (i >= coins and dp[i - coins][!isa]) {
                        dp[i][isa] = 1;
                    }
                }
            }
        }
    }
    for (int coins : {1, x, y}) {
        if (n >= coins and dp[n - coins][1]) {
            return 'A';
        }
    }
    return 'B';
}

int main() { TimeMeasure _; __x();
    int n1 = 5, x1 = 3, y1 = 4;
    int n2 = 2, x2 = 3, y2 = 4;
    cout << rec(n1, x1, y1) << endl; // A
    cout << rec(n2, x2, y2) << endl; // B
    cout << endl;
    cout << tab(n1, x1, y1) << endl; // A
    cout << tab(n2, x2, y2) << endl; // B
}
