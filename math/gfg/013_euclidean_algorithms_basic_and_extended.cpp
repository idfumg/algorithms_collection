#include "../../template.hpp"

int BasicGcd(int a, int b) {
    if (a == 0) return b;
    return BasicGcd(b % a, a);
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

int main() { TimeMeasure _;
    cout << BasicGcd(35, 15) << endl; // 5
    cout << BasicGcd(10, 15) << endl; // 5
    cout << BasicGcd(31, 2) << endl; // 1
    cout << endl;
    cout << ExtendedGcd(35, 15) << endl; // 5
    cout << ExtendedGcd(10, 15) << endl; // 5
    cout << ExtendedGcd(31, 2) << endl; // 1
    cout << endl;
    cout << ExtendedGcd2(35, 15) << endl; // 5
    cout << ExtendedGcd2(10, 15) << endl; // 5
    cout << ExtendedGcd2(31, 2) << endl; // 1
}
