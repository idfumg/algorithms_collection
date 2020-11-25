#include "../../template.hpp"

int MaxOccuringDivisor(int a, int b) {
    if (a == b) return a;
    return 2;
}

int main() { TimeMeasure _;
    cout << MaxOccuringDivisor(2, 5) << endl; // 2
    cout << MaxOccuringDivisor(3, 3) << endl; // 3
}
