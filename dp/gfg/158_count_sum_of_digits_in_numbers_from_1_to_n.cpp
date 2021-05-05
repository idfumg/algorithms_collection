#include "../../template.hpp"

int naive(int num) {
    int ans = 0;
    for (int i = 1; i <= num; ++i) {
        for (int n = i; n > 0; n /= 10) {
            ans += n % 10;
        }
    }
    return ans;
}

int rec_(int n) {
    if (n < 10) return n;
    return n % 10 + rec_(n / 10);
}

int rec(int n) {
    if (n == 0) return 0;
    return rec_(n) + rec(n - 1);
}

int tab(int n) {
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        if (i < 10) dp[i] = i;
        else dp[i] = i % 10 + dp[i / 10];
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        ans += dp[i];
    }
    return ans;
}

int main() { // TimeMeasure _; __x();
    cout << naive(5) << endl; // 15
    cout << naive(12) << endl; // 51
    cout << naive(328) << endl; // 3241
    cout << rec(5) << endl; // 15
    cout << rec(12) << endl; // 51
    cout << rec(328) << endl; // 3241
    cout << tab(5) << endl; // 15
    cout << tab(12) << endl; // 51
    cout << tab(328) << endl; // 3241
}
