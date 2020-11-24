#include "../../template.hpp"

vi Sieve(int n, int from) {
    vb isprime(n + 1, true);
    for (int p = 2; p * p <= n; ++p) {
        if (isprime[p]) {
            for (int i = p * p; i <= n; i += p) {
                isprime[i] = false;
            }
        }
    }
    vi primes;
    for (int i = 2; i <= n; ++i) {
        primes.push_back(i);
    }
    return primes;
}

int NumbersWithNDivisors(int a, int b, int n) {
    vi primes = Sieve(n, a);
    int ans = 0;
    for (int num = a; num <= b; ++num) {
        int count = 2; // 1 + itself divisors
        int number = num;
        for (int prime : primes) {
            while (number % prime == 0) {
                ++count;
                number /= prime;
            }
        }
        if (count == n) {
            ++ans;
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << NumbersWithNDivisors(1, 7, 2) << endl; // 4
}
