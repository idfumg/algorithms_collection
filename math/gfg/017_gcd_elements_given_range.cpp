#include "../../template.hpp"

int GcdOfRange(int m, int n) {
    // gcd(a1, a2, a3, ..., an-1, an) = gcd(gcd(a1, a2, a3, ..., an-1), an) =
    // gcd(gcd(a1, a2), a3, ..., an-1, an) = gcd(gcd(m, m + 1), a3, ..., an-1, an)
    // gcd(m, m + 1) = gcd(odd, even) = 1
    if (m == n) return m;
    return 1;
}

int main() { TimeMeasure _; __x();
    cout << GcdOfRange(1, 2) << endl; // 1
    cout << GcdOfRange(475, 475) << endl; // 475
}
