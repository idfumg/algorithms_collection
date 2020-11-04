#include "../../template.hpp"

int KthLargestSum(vi arr, int k) {
    int n = arr.size();
    vi presum(n + 1);
    presum[1] = arr[0];
    for (int i = 2; i <= n; ++i) {
        presum[i] = presum[i - 1] + arr[i - 1];
    }
    vi sums;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            sums.push_back(presum[j] - presum[i - 1]);
        }
    }
    sort(sums.begin(), sums.end());
    int m = sums.size();
    return m >= k ? sums[m - k] : sums.back();
}

int main() { TimeMeasure _;
    cout << KthLargestSum({20, -5, -1}, 3) << '\n';
    cout << KthLargestSum({10, -10, 20, -40}, 6) << '\n';
}
