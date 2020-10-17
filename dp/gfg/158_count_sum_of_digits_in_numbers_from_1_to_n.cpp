#include "../../template.hpp"

int SumOfDigits(int n) {
    int res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int naive(int n) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        res += SumOfDigits(i);
    }
    return res;
}

int tab(int n) {
    vi dp(n + 1);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i / 10] + i % 10;
    }
    return accumulate(dp.begin(), dp.end(), 0);
}

int main() { TimeMeasure _; __x();
    cout << naive(5) << endl; // 15
    cout << naive(12) << endl; // 51
    cout << naive(328) << endl; // 3241
    cout << tab(5) << endl; // 15
    cout << tab(12) << endl; // 51
    cout << tab(328) << endl; // 3241
}
