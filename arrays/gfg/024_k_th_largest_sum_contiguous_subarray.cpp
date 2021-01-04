#include "../../template.hpp"

int KthLargestSum(vi arr, int k) {
    int n = arr.size();

    vi prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }

    multiset<int> sums;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            sums.insert(prefix[j] - prefix[i - 1]);
            if (sums.size() > k) {
                sums.erase(sums.begin());
            }
        }
    }
    return *sums.begin();
}

int main() { TimeMeasure _;
    cout << KthLargestSum({20, -5, -1}, 3) << '\n'; // 14
    cout << KthLargestSum({10, -10, 20, -40}, 6) << '\n'; // -10
}
