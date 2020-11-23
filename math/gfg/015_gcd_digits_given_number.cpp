#include "../../template.hpp"

int GcdOfDigits(int n) {
    int ans = n % 10;
    n /= 10;
    while (n > 0) {
        ans = gcd(ans, n % 10);
        n /= 10;
        if (ans == 1) return 1;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << GcdOfDigits(345) << endl; // 1
    cout << GcdOfDigits(2448) << endl; // 2
}
