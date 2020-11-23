#include "../../template.hpp"

int LcmOfFactorialAndNeighbors(int num) {
    int a = 1, b = 2, n = num;
    while (n-- > 0) {
        a *= b;
        ++b;
    }
    int x = a / (b - 1) / (b - 2);
    int y = a / (b - 1);
    int z = a;
    return lcm(x, lcm(y, z));
}

int optimized(int n) {
    int a = 1, b = 2;
    while (n-- > 0) {
        a *= b;
        ++b;
    }
    return a;
}

int main() { TimeMeasure _; __x();
    cout << LcmOfFactorialAndNeighbors(5) << endl; // 720
    cout << LcmOfFactorialAndNeighbors(3) << endl; // 24
    cout << endl;
    cout << optimized(5) << endl; // 720
    cout << optimized(3) << endl; // 24
}
