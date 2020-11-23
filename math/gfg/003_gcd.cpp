#include "../../template.hpp"

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int gcd2(int a, int b) {
    return std::gcd(a, b);
}

int main() { TimeMeasure _;
    cout << gcd(3, 15) << endl; // 3
    cout << gcd(2, 4) << endl; // 2
    cout << gcd(3, 5) << endl; // 1
    cout << gcd(6, 36) << endl; // 6
    cout << endl;
    cout << gcd2(3, 15) << endl; // 3
    cout << gcd2(2, 4) << endl; // 2
    cout << gcd2(3, 5) << endl; // 1
    cout << gcd2(6, 36) << endl; // 6
}
