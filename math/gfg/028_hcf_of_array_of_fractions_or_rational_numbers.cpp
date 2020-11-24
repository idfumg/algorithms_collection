#include "../../template.hpp"

int ArrayLcm(vi arr) {
    int ans = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        ans = lcm(ans, arr[i]);
    }
    return ans;
}

int ArrayGcd(vi arr) {
    int ans = arr[0];
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        ans = gcd(ans, arr[i]);
    }
    return ans;
}

void GcdOfFractions(vi nums, vi denoms)  {
    int nr = ArrayLcm(denoms);
    int dr = ArrayGcd(nums);
    cout << dr << '/' << nr << endl;
}

int main() { TimeMeasure _;
    GcdOfFractions({2, 8, 16, 10},
                   {5, 9, 81, 27}); // 2/405

    GcdOfFractions({9, 12, 18, 21},
                   {10, 25, 35, 40}); // 3/1400
}
