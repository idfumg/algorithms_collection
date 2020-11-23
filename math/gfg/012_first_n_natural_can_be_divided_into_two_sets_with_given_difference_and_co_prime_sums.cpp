#include "../../template.hpp"

bool IsNaturalNumbersCanBeDividedIntoSubsets(int n, int m) {
    int sum = n * (n + 1) / 2;
    // x + y = sum
    // x - y = m

    // x = sum - y
    // y = x - m

    // y = sum - y - m
    // 2 * y = sum - m

    // y = (sum - m) / 2
    // x = sum - y

    int y = (sum - m) / 2;
    int x = sum - y;

    if ((x + y) != sum or abs(x - y) != m) {
        return false;
    }
    return gcd(x, y) == 1;
}

int main() { TimeMeasure _;
    cout << IsNaturalNumbersCanBeDividedIntoSubsets(5, 7) << endl; // 1
    cout << IsNaturalNumbersCanBeDividedIntoSubsets(6, 3) << endl; // 0
}
