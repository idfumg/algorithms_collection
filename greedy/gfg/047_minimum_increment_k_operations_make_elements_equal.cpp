#include "../../template.hpp"

int MinIncrementToMakeEqual(vi arr, int k) {
    if (arr.empty()) return 0;
    int ans = 0, n = arr.size(), large = *max_element(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        if ((large - arr[i]) % k > 0) return -1;
        ans += (large - arr[i]) / k;
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << MinIncrementToMakeEqual({4,7,19,16}, 3) << '\n';
    cout << MinIncrementToMakeEqual({4,4,4,4}, 3) << '\n';
    cout << MinIncrementToMakeEqual({4,2,6,8}, 3) << '\n';
}
