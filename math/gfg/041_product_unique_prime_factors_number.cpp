#include "../../template.hpp"

ll ProductOfPrimeFactors(ll n) {
    ll ans = 1;
    if (n % 2 == 0) {
        ans *= 2;
    }
    while (n % 2 == 0) {
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            ans *= i;
        }
        while (n % i == 0) {
            n /= i;
        }
    }
    if (n > 2) {
        ans *= n;
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << ProductOfPrimeFactors(10) << endl; // 10
    cout << ProductOfPrimeFactors(25) << endl; // 5
    cout << ProductOfPrimeFactors(44) << endl; // 22
}
