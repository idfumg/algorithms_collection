#include "../../template.hpp"

vi Sieve(int n) {
    vb isprime(n + 1, true);
    for (int p = 2; p * p <= n; ++p) {
        if (isprime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isprime[i] = false;
            }
        }
    }
    vi primes;
    for (int p = 2; p <= n; ++p) {
        if (isprime[p]) {
            primes.push_back(p);
        }
    }
    return primes;
}

void Factorization(int n) {
    vi primes = Sieve(n);
    while (n > 1) {
        for (int i = 0; i < n; ++i) {
            while (n > 0 and n % primes[i] == 0) {
                cout << primes[i] << ' ';
                n /= primes[i];
            }
        }
    }
}

int main() { TimeMeasure _;
    Factorization(12246); // 2 3 13 157
}
