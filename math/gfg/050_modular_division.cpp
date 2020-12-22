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

int ModDivision(int x, int y, int m) {
    int xinv = ModInverse(y, m);
    if (xinv == -1) {
        return -1;
    }
    return (x * xinv) % m;
}

int main() { TimeMeasure _;
    cout << ModDivision(8, 3, 5) << endl; // 1
    cout << ModDivision(8, 4, 5) << endl; // 2
    cout << ModDivision(11, 4, 5) << endl; // 4
}
