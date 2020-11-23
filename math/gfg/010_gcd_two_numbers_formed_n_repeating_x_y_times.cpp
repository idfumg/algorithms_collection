#include "../../template.hpp"

void GcdOfRepeatingNumbers(int n, int x, int y) {
    // gcd(f(n, x), f(n, y)) == f(n, gcd(x, y))
    int ans = 0;
    int g = gcd(x, y);
    for (int i = 0; i < g; ++i) {
        cout << n;
    }
    cout << endl;
}

int main() { TimeMeasure _;
    GcdOfRepeatingNumbers(123, 2, 3); // 123
    GcdOfRepeatingNumbers(4, 4, 6); // 44
    GcdOfRepeatingNumbers(123, 5, 2); // 123
}
