#include "../template.hpp"

int SumOfDigits(int n) {
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

void SmallestNumWithSumN(int n) {
    int ans = 0;
    while (SumOfDigits(ans) != n) {
        ++ans;
    }
    cout << ans << string(n, '0') << '\n';
}

int main() { TimeMeasure _; __x();
    SmallestNumWithSumN(5); // 500000
    SmallestNumWithSumN(20); // 29900000000000000000000
}
