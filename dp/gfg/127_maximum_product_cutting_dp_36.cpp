#include "../../template.hpp"

int rec(int n) {
    if (n == 0) return 0;
    if (n == 1) return 0;
    int maxi = -INF;
    for (int i = 1; i < n; ++i) {
        maxi = max({maxi, i * (n - i), rec(n - i) * i});
    }
    return maxi;
}

int rec2(int n) {
    if (n == 0 or n == 1) return 0;
    int maxi = -INF;
    for (int i = 1; i < n; ++i) {
        maxi = max({maxi, rec2(n - i) * i, (n - i) * i});
    }
    return maxi;
}

int tab(int n) {
    vi dp(n + 1);
    for (int i = 0; i <= n; ++i) {
        if (i == 0 or i == 1) {
            dp[i] = 0;
        }
        else {
            int maxi = -INF;
            for (int k = 1; k < i; ++k) {
                maxi = max({maxi, k * (i - k), dp[i - k] * k});
            }
            dp[i] = maxi;
        }
    }
    return dp[n];
}

int tab2(int n) {
    // dp[i] - max product of cutting a rod of length i
    vi dp(n + 1);
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i - 1; ++j) {
            dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
        }
    }
    return dp[n];
}

int main() { TimeMeasure _; __x();
    cout << rec(2) << endl; // 1
    cout << rec(3) << endl; // 2
    cout << rec(4) << endl; // 4
    cout << rec(5) << endl; // 6
    cout << rec(10) << endl; // 36
    cout << endl;
    cout << rec2(2) << endl; // 1
    cout << rec2(3) << endl; // 2
    cout << rec2(4) << endl; // 4
    cout << rec2(5) << endl; // 6
    cout << rec2(10) << endl; // 36
    cout << endl;
    cout << tab(2) << endl; // 1
    cout << tab(3) << endl; // 2
    cout << tab(4) << endl; // 4
    cout << tab(5) << endl; // 6
    cout << tab(10) << endl; // 36
    cout << endl;
    cout << tab2(2) << endl; // 1
    cout << tab2(3) << endl; // 2
    cout << tab2(4) << endl; // 4
    cout << tab2(5) << endl; // 6
    cout << tab2(10) << endl; // 36
}
