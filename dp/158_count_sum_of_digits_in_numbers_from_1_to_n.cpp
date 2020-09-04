#include "../template.hpp"

int naive(int num) {
    int total = 0;
    for (int i = 1; i <= num; ++i) {
        int n = i;
        while (n > 0) {
            total += n % 10;
            n /= 10;
        }
    }
    return total;
}

int tab(int n) {
    vi dp(n);
    int total = 0;
    for (int i = 1; i <= n; ++i) {
        if (i < 10) {
            dp[i] = i;
        }
        else {
            dp[i] = i % 10 + dp[i / 10];
        }
        total += dp[i];
    }
    return total;
}

int main() { TimeMeasure _; __x();
    cout << naive(5) << endl;
    cout << naive(12) << endl;
    cout << naive(328) << endl;
    cout << tab(5) << endl;
    cout << tab(12) << endl;
    cout << tab(328) << endl;
}
