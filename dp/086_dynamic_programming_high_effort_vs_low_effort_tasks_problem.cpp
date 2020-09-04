#include "../template.hpp"

int rec(vi& high, vi& low, int n) {
    if (n <= 0) return 0;
    return max(low[n - 1] + rec(high, low, n - 1),
               high[n - 1] + rec(high, low, n - 3));
}

int rec(vi& high, vi& low) {
    return rec(high, low, high.size());
}

int tab(vi& high, vi& low) {
    const int n = high.size();
    vi dp(3);
    for (int i = 1; i <= n; ++i) {
        dp[i % 3] = max(low[i - 1] + dp[(i + 2) % 3],
                        high[i - 1] + (i >= 2 ? dp[(i + 1) % 3] : 0));
    }
    return dp[n % 3];
}

int main() { TimeMeasure _; __x();
    vi high = {3, 6, 8, 7, 6};
    vi low = {1, 5, 4, 5, 3};
    cout << rec(high, low) << endl;
    cout << tab(high, low) << endl;
}
