#include "../../template.hpp"

vi Sieve(int n) {
    vb isprime(n + 1 ,true);
    for (int p = 2; p * p <= n; ++p) {
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

void Factorization(int n) {
    vi primes = Sieve(n);
    for (int i = 0; i < primes.size() and n > 1; ++i) {
        while (n >= 1 and n % primes[i] == 0) {
            cout << primes[i] << ' ';
            n /= primes[i];
        }
    }
    cout << endl;
}

int main() { TimeMeasure _;
    Factorization(12246); // 2 3 13 157
}
