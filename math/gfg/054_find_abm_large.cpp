#include "../../template.hpp"

int ModPower(int x, int b, int m) {
    x = x % m;
    if (x == 0) {
        return x;
    }
    int res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        b /= 2;
    }
    return res;
}

int ModOfHugeNumber(const string& a, int m) {
    int ans = 0;
    for (char ch : a) {
        ans = (ans * 10 + ch - '0') % m;
    }
    return ans;
}

int HugeAPowerBModM(const string& a, int b, int m) {
    int x = ModOfHugeNumber(a, m);
    return ModPower(x, b, m);
}

int main() { TimeMeasure _;
    cout << HugeAPowerBModM("3", 2, 4) << endl; // 1
    cout << HugeAPowerBModM("987584345091051645734583954832576", 3, 11) << endl; // 10
}
