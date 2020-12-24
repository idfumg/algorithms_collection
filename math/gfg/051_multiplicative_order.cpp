#include "../../template.hpp"

int MultiplicativeOrder(int n, int m) {
    if (gcd(n, m) != 1) {
        return -1;
    }
    int prod = 1;
    for (int k = 1; k < m; ++k) {
        prod = (prod * n) % m;
        if (prod == 1) {
            return k;
        }
    }
    return -1;
}

int main() { TimeMeasure _;
    cout << MultiplicativeOrder(4, 7) << endl; // 3
    cout << MultiplicativeOrder(3, 1000) << endl; // 100
    cout << MultiplicativeOrder(4, 11) << endl; // 5
}
