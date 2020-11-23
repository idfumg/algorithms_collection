#include "../../template.hpp"

// gcd(lcm(x, y), lcm(x, z)) == lcm(x, gcd(y, z))
int GCDDistributiveProperty(int x, int y, int z) {
    return lcm(x, gcd(y, z));
}

int main() { TimeMeasure _;
    cout << GCDDistributiveProperty(15, 20, 100) << endl; // 60
    cout << GCDDistributiveProperty(30, 40, 400) << endl; // 120
}
