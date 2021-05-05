#include "../../template.hpp"

int ProductOfFactors(int n) {
    int mod = 1e9 + 7;
    int ans = 1;
    for (int i = 1; i <= sqrt(n); ++i) {
        if (n % i == 0) {
            ans *= i;
            ans %= mod;
            if (n / i != i) {
                ans *= n / i;
                ans %= mod;
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << ProductOfFactors(12) << endl; // 1728
    cout << ProductOfFactors(18) << endl; // 5832
}
