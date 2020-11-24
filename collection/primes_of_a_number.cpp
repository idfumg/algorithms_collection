#include "../template.hpp"

void PrimeFactors(int n) {
    while ((n & 1) == 0) {
        cout << 2 << ' ';
        n /= 2;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        while (n % i == 0) {
            cout << i << ' ';
            n /= i;
        }
    }
    if (n > 2) {
        cout << n;
    }
    cout << endl;
}

int main() { TimeMeasure _;
    PrimeFactors(12); // 2 2 3
    PrimeFactors(315); // 3 3 5 7
}
