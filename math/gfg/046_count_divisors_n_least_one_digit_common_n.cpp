#include "../../template.hpp"

unordered_set<int> GetDigits(int n) {
    unordered_set<int> digits;
    while (n > 0) {
        digits.insert(n % 10);
        n /= 10;
    }
    return digits;
}

void DivisorsWithCommonDigit(int n) {
    int ans = 0;
    const unordered_set<int> digits = GetDigits(n);
    for (int i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            for (int digit : GetDigits(i)) {
                if (digits.count(digit)) {
                    ++ans;
                    break;
                }
            }
            for (int digit : GetDigits(n / i)) {
                if (digits.count(digit)) {
                    ++ans;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

int main() { TimeMeasure _;
    DivisorsWithCommonDigit(10); // 2
    DivisorsWithCommonDigit(15); // 3
}
