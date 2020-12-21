#include "../../template.hpp"

int ModPower(int x, int p, int m) {
    x = x % m;
    if (x == 0) {
        return x;
    }
    int ans = 1;
    while (p > 0) {
        if (p & 1) {
            ans = (ans * x) % m;
        }
        p /= 2;
        x = (x * x) % m;
    }
    return ans;
}

int ModInverse(int x, int m) {
    if (gcd(x, m) != 1) {
        return -1;
    }
    return ModPower(x, m - 2 , m);
}

int main() { TimeMeasure _;
    cout << ModInverse(3, 11) << endl; // 4
}
