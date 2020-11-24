#include "../template.hpp"

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

int gcd2(int a, int b) {
    return std::gcd(a, b);
}

int ExtendedGcd(int a, int b) {
    if (a < b) return ExtendedGcd(b, a);
    if (b == 0) return a;
    return ExtendedGcd(b, a - floor(a / b) * b);
}

int ExtendedGcd2(int a, int b, int& x, int& y) {
    if (a < b) {
        return ExtendedGcd2(b, a, x, y);
    }

    if (b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    int x1 = 0;
    int y1 = 0;
    int g = ExtendedGcd2(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;

    return g;
}

int ExtendedGcd2(int a, int b) {
    // a*x + b*y = gcd(a, b)
    int x = 0;
    int y = 0;
    int g = ExtendedGcd2(a, b, x, y);
    debug(x); debugn(y);
    return g;
}

int iter(int a, int b) {
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
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
    cout << endl;
    cout << ExtendedGcd(3, 15) << endl; // 3
    cout << ExtendedGcd(2, 4) << endl; // 2
    cout << ExtendedGcd(3, 5) << endl; // 1
    cout << ExtendedGcd(6, 36) << endl; // 6
    cout << endl;
    cout << ExtendedGcd2(3, 15) << endl; // 3
    cout << ExtendedGcd2(2, 4) << endl; // 2
    cout << ExtendedGcd2(3, 5) << endl; // 1
    cout << ExtendedGcd2(6, 36) << endl; // 6
    cout << endl;
    cout << iter(3, 15) << endl; // 3
    cout << iter(2, 4) << endl; // 2
    cout << iter(3, 5) << endl; // 1
    cout << iter(6, 36) << endl; // 6
}
