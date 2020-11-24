#include "../../template.hpp"

int brute(int n, int k) {
    int p = pow(10, k);
    for (int i = 1; i * p <= 1e9; ++i) {
        int current = p * i;
        if (current % n == 0) {
            return current;
        }
    }
    return -1;
}

int fast(int n, int k) {
    int p = pow(10, k);
    return std::lcm(n, p);
}

int main() { TimeMeasure _;
    cout << brute(30, 3) << endl; // 3000
    cout << brute(375, 4) << endl; // 30000
    cout << endl;
    cout << fast(30, 3) << endl; // 3000
    cout << fast(375, 4) << endl; // 30000
}
