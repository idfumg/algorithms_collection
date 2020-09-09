#include "../template.hpp"

vi SieveOfEratosthenes(int n) {
    vb prime(n + 1, true);
    for (int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }
    vi primes;
    for (int i = 2; i <= n; ++i) {
        if (prime[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

int main() { TimeMeasure _;
    int n = 50;
    cout << "Prime numbers smaller than or equal to " << n << '\n';
    cout << SieveOfEratosthenes(n) << endl;
}
