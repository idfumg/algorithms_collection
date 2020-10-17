#include "../../template.hpp"

int MinSumOfAbsDifferences(vi arr1, vi arr2) {
    if (arr1.size() != arr2.size()) return INF;
    sort(arr1);
    sort(arr2);
    int sum = 0, n = arr1.size();
    for (int i = 0; i < n; ++i) {
        sum += abs(arr1[i] - arr2[i]);
    }
    return sum;
}

int main() { TimeMeasure _;
    cout << MinSumOfAbsDifferences({3, 2, 1}, {2, 1, 3}) << '\n'; // 0
    cout << MinSumOfAbsDifferences({4, 1, 8, 7}, {2, 3, 6, 5}) << '\n'; // 6
}
