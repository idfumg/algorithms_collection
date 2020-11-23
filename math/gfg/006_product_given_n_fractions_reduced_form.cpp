#include "../../template.hpp"

void ReducedProductOfNFractions(vi nrs, vi drs) {
    int num = reduce(nrs.begin(), nrs.end(), 1, multiplies<int>());
    int denom = reduce(drs.begin(), drs.end(), 1, multiplies<int>());
    int g = gcd(num, denom);
    cout << num / g << '/' << denom / g << endl;
}

int main() { TimeMeasure _;
    ReducedProductOfNFractions({1, 2, 5}, {2, 1, 6}); // 5/6
    ReducedProductOfNFractions({1, 2, 5, 9}, {2, 1, 6, 27}); // 5/18
}
