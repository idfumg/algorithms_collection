#include "../../template.hpp"

ll LargeNumbersModuloMultiplication(ll a, ll b, ll m) {
    // f(a, b)
    // b is even: 2 * a * (b / 2)
    // b is odd: a + a * (b - 1)

    a = a % m;
    if (a == 0) {
        return a;
    }
    ll ans = 0;
    while (b > 0) {
        if (b & 1) {
            ans = (ans + a) % m;
        }
        a = (2 * a) % m;
        b /= 2;
    }
    return ans;
}

int main() { TimeMeasure _;
    // 4652135769797794
    cout << LargeNumbersModuloMultiplication(10123465234878998LL, 65746311545646431LL, 10005412336548794LL) << endl;
}
