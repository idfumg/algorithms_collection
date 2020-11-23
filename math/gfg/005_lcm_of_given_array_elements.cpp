#include "../../template.hpp"

int LCMOfArray(vi arr) {
    int n = arr.size();
    int ans = arr[0];
    for (int i = 1; i < n; ++i) {
        ans = std::lcm(ans, arr[i]);
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << LCMOfArray({1, 2, 8, 3}) << endl; // 24
    cout << LCMOfArray({2, 7, 3, 9, 4}) << endl; // 252
}
