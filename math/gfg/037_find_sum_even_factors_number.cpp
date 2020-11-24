#include "../../template.hpp"

int SumOfEvenFactors(int n) {
    if ((n & 1) != 0) {
        return 0;
    }
    int ans = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0 and i % 2 == 0) {
            ans += i;
        }
    }
    for (int i = n; i >= sqrt(n); --i) {
        if (n % i == 0 and i % 2 == 0) {
            ans += i;
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << SumOfEvenFactors(30) << endl; // 48
    cout << SumOfEvenFactors(18) << endl; // 26
}
