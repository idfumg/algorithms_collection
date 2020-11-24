#include "../../template.hpp"

void MaxOfTwoRationals(vi nrs, vi drs) {
    int n = nrs.size();
    int lcm = std::lcm(drs[0], drs[1]);
    int x = nrs[0] * (lcm / drs[0]);
    int y = nrs[1] * (lcm / drs[1]);
    if (x > y) {
        cout << nrs[0] << '/' << drs[0] << endl;
    }
    else {
        cout << nrs[1] << '/' << drs[1] << endl;
    }
}

int main() { TimeMeasure _;
    MaxOfTwoRationals({3, 3},
                      {4, 2}); // 3/2

    MaxOfTwoRationals({100, 300},
                      {100, 400}); // 100/100
}
