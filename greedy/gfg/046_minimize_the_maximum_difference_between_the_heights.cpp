#include "../../template.hpp"

void GetMinDiff(int a, int b, int k, int& x, int& y) {
    if (a < 0 or b < 0) {
        return;
    }
    if (abs(x - y) > abs(a - b)) {
        x = a;
        y = b;
    }
}

pair<int, int> GetMinDiff(int a, int b, int k) {
    int x = 0, y = INF;
    GetMinDiff(a - k, b - k, k, x, y);
    GetMinDiff(a + k, b + k, k, x, y);
    GetMinDiff(a - k, b + k, k, x, y);
    GetMinDiff(a + k, b - k, k, x, y);
    return {min(x, y), max(x, y)};
}

int MinimizeDifferenceBetweenHeightsDP(vi arr, int k) {
    int n = arr.size();
    if (n < 1) return arr.front();
    sort(arr);
    auto [low, high] = GetMinDiff(arr[0], arr[n - 1], k);
    for (int i = 1; i < n - 1; ++i) {
        int a = arr[i] - k;
        int b = arr[i] + k;

        if (a < 0) {
            high = max(high, b);
            continue;
        }

        if (a >= low or b <= high) {
            continue;
        }

        if (high - a <= b - low) {
            low = a;
        }
        else {
            high = b;
        }
    }
    return high - low;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 15, 10}; int k1 = 6;
    vi arr2 = {1, 5, 15, 10}; int k2 = 3;
    vi arr3 = {4, 6}; int k3 = 10;
    vi arr4 = {6, 10}; int k4 = 3;
    vi arr5 = {1, 10, 14, 14, 14, 15}; int k5 = 6;
    vi arr6 = {1, 2, 3}; int k6 = 2;

    cout << MinimizeDifferenceBetweenHeightsDP(arr1, k1) << '\n'; // 5
    cout << MinimizeDifferenceBetweenHeightsDP(arr2, k2) << '\n'; // 8
    cout << MinimizeDifferenceBetweenHeightsDP(arr3, k3) << '\n'; // 2
    cout << MinimizeDifferenceBetweenHeightsDP(arr4, k4) << '\n'; // 2
    cout << MinimizeDifferenceBetweenHeightsDP(arr5, k5) << '\n'; // 5
    cout << MinimizeDifferenceBetweenHeightsDP(arr6, k6) << '\n'; // 2
}
