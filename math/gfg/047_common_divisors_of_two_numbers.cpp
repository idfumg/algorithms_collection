#include "../../template.hpp"

void CommonDivisorsOfTwoNumbers(int a, int b) {
    int n = std::gcd(a, b);
    for (int i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            cout << i << ' ';
        }
    }
    for (int i = ceil(sqrt(n)); i <= n; ++i) {
        if (n % i == 0) {
            cout << i << ' ';
        }
    }
    cout << endl;
}

int main() { TimeMeasure _;
    CommonDivisorsOfTwoNumbers(12, 24); // 1, 2, 3, 4, 6, 12
    CommonDivisorsOfTwoNumbers(3, 17); // 1
    CommonDivisorsOfTwoNumbers(20, 36); // 1, 2, 4
}
