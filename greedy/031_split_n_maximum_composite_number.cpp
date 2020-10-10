#include "../template.hpp"

bool IsPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 or n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 or n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

bool IsComposite(int n) {
    return not IsPrime(n);
}

int SplitIntoMaxCompositeNumbers(int n) {
    int i = 4, ans = 0;
    if (IsPrime(n)) {
        return 0;
    }
    while (n != 0) {
        if (not IsComposite(i)) {
            ++i;
            continue;
        }
        int count = n / i;
        if (n != count * i) {
            --count;
        }
        n -= count * i;
        ans += count;
        ++i;
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << SplitIntoMaxCompositeNumbers(90) << '\n'; // 22
    cout << SplitIntoMaxCompositeNumbers(10) << '\n'; // 2
    cout << SplitIntoMaxCompositeNumbers(143) << '\n'; // 34
    cout << SplitIntoMaxCompositeNumbers(11) << '\n'; // 2
    cout << SplitIntoMaxCompositeNumbers(12) << '\n'; // 3
}
