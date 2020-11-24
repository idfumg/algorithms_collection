#include "../../template.hpp"

int brute(int n, int k, int m) {
    int steps = 1;
    int position = (k + m) % n;
    for (; steps < 1e9; ++steps) {
        if (position == k) {
            return steps;
        }
        position = (position + m) % n;
    }
    return steps;
}

int fast(int n, int k, int m) {
    return n / std::gcd(n ,m);
}

int main() { TimeMeasure _;
    cout << brute(9, 2, 6) << endl; // 3 // O(n)
    cout << brute(6, 3, 2) << endl; // 3
    cout << endl;
    cout << fast(9, 2, 6) << endl; // 3 // O(logn)
    cout << fast(6, 3, 2) << endl; // 3
}
