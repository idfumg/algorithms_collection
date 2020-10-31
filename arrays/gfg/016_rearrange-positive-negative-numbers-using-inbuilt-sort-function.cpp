#include "../../template.hpp"

bool pred(int a, int b) {
    if (a < 0 and b > 0) return true;
    if (a < 0 and b == 0) return true;
    if (a == 0 and b > 0) return true;
    return false;
}

void RearrangeSameOrder(vi arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end(), pred);
    cout << arr << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {12, 11, -13, -5, 6, -7, 5, -3, -6};
    vi arr2 = {-12, 11, 0, -5, 6, -7, 5, -3, -6};

    RearrangeSameOrder(arr1);
    RearrangeSameOrder(arr2);
}
