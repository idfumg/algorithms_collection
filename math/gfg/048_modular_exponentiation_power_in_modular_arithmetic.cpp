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

int main() { TimeMeasure _;
    cout << ModPower(2, 5, 13) << endl; // 6
}
