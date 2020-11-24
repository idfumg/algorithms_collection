#include "../../template.hpp"

bool CanBeMadeEqualByPrimes(vi arr, vi primes) {
    int lcm = arr[0];
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        lcm = std::lcm(lcm, arr[i]);
    }
    for (int i = 0; i < n; ++i) {
        int n = lcm / arr[i];
        for (int prime : primes) {
            while (n % prime == 0) {
                n /= prime;
            }
        }
        if (n != 1) {
            return false;
        }
    }
    return true;
}

int main() { TimeMeasure _;
    cout << CanBeMadeEqualByPrimes({50, 200}, {2, 3}) << endl; // 1
    cout << CanBeMadeEqualByPrimes({3, 4, 5, 6, 2}, {2, 3}) << endl; // 0
}
