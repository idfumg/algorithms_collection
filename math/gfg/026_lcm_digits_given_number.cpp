#include "../../template.hpp"

int LcmOfDigits(int n) {
    int ans = n % 10;
    n /= 10;
    while (n > 0) {
        ans = lcm(ans, n % 10);
        n /= 10;
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << LcmOfDigits(397) << endl; // 63
    cout << LcmOfDigits(244) << endl; // 4
}
