#include "../../template.hpp"

int ArrayLcm(vi arr) {
    int n = arr.size();
    int ans = arr[0];
    for (int i = 1; i < n; ++i) {
        ans = lcm(ans, arr[i]);
    }
    return ans;
}

int ArrayGcd(vi arr) {
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = gcd(ans, arr[i]);
    }
    return ans;
}

void LCMOfRationals(vi nums, vi denoms) {
/*
x    a   x * b   x   b
_  / _ = _____ = _ * _
y    b   y * a   a   y
*/
    int n = nums.size();
    int lcm_ = ArrayLcm(nums);
    int gcd_ = ArrayGcd(denoms);
    cout << lcm_ << '/' << gcd_ << endl;
}

int main() { TimeMeasure _; __x();
    LCMOfRationals({2, 3, 5}, {7, 14, 3}); // 30/1
    LCMOfRationals({3, 5}, {14, 3}); // 15/1
    LCMOfRationals({3, 3}, {4, 2}); // 3/2
}
