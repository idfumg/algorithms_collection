#include "../../template.hpp"

void KPrimesInARange(int a, int b, int k) { // sieve
    vi primesCount(b + 1, 0);
    for (int p = 2; p <= b; ++p) {
        if (primesCount[p] == 0) {
            for (int i = 2 * p; i <= b; i += p) {
                ++primesCount[i];
            }
        }
    }
    for (int i = a; i <= b; ++i) {
        if (primesCount[i] == k) {
            cout << i << ' ';
        }
    }
    cout << endl;
}

int main() { TimeMeasure _;
    KPrimesInARange(4, 10, 2); // 6 10
    KPrimesInARange(14, 18, 2); // 14 15 18
}
