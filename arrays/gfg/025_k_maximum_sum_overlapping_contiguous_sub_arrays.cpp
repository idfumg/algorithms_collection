#include "../../template.hpp"

void GetKMaxSums(vi arr, int k) {
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
    for_each(sums.rbegin(), sums.rbegin() + k, [](int param){cout << param << ' ';});
    cout << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {4, -8, 9, -4, 1, -8, -1, 6}; int k1 = 4;
    vi arr2 = {-2, -3, 4, -1, -2, 1, 5, -3}; int k2 = 3;

    GetKMaxSums(arr1, k1);
    GetKMaxSums(arr2, k2);
}
