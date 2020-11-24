#include "../../template.hpp"

vi Sieve(int n) {
    vb isprime(n + 1, true);
    for (int p = 2; p * p < n; ++p) {
        if (isprime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isprime[i] = false;
            }
        }
    }
    vi primes;
    for (int i = 2; i <= n; ++i) {
        if (isprime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() { TimeMeasure _;
    cout << Sieve(10) << endl; // 2 3 5 7
    cout << Sieve(20) << endl; // 2 3 5 7 11 13 17 19
    cout << Sieve(30) << endl; // 2 3 5 7 11 13 17 19 23 29
}
