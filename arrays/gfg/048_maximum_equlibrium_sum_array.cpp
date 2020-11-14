#include "../../template.hpp"

void MaxEquilibriumSum(vi arr) {
    int n = arr.size();
    vi prefixsum(n);
    prefixsum[0] = arr[0];
    for (int i = 1; i < n; ++i) {
        prefixsum[i] = prefixsum[i - 1] + arr[i];
    }
    vi suffixsum(n);
    suffixsum[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffixsum[i] = suffixsum[i + 1] + arr[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (prefixsum[i] == suffixsum[i]) {
            ans = max(ans, prefixsum[i]);
        }
    }
    debugn(ans);
}

int main() { TimeMeasure _;
    MaxEquilibriumSum({-1, 2, 3, 0, 3, 2, -1});
    MaxEquilibriumSum({-2, 5, 3, 1, 2, 6, -4, 2});
}
