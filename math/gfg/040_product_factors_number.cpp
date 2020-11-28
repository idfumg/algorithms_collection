#include "../../template.hpp"

ll ProductOfFactors(ll n) {
    ll ans = 1;
    for (int i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            ans *= i;
        }
    }
    for (int i = sqrt(n); i >= 1; --i) {
        if (n % i == 0) {
            ans *= n / i;
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << ProductOfFactors(12) << endl; // 1728
    cout << ProductOfFactors(18) << endl; // 5832
}
