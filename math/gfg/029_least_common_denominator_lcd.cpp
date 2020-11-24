#include "../../template.hpp"

int ArrayLcm(vi arr) {
    int ans = arr[0];
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        ans = lcm(ans, arr[i]);
    }
    return ans;
}

void LeastCommonDenominator(vi nrs, vi drs) {
    int denominator = ArrayLcm(drs);
    int numerator = 0;
    int n = nrs.size();
    for (int i = 0; i < n; ++i) {
        numerator += (denominator / drs[i]) * nrs[i];
    }
    int gcd = std::gcd(denominator, numerator);
    cout << numerator / gcd << '/' << denominator / gcd << endl;
}

int main() { TimeMeasure _;
    LeastCommonDenominator({1, 7},
                           {6, 15}); // 19/30

    LeastCommonDenominator({1, 1},
                           {3, 6}); // 3/6 == 1/2
}
