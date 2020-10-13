#include "../template.hpp"

void GetMinDistance(int a, int b, int k, int& low, int& high) {
    if (a < 0 or b < 0) return;
    if (abs(a - b) < abs(low - high)) {
        low = min(a, b);
        high = max(a, b);
    }
}

pair<int, int> GetDistance(int a, int b, int k) {
    int low = 0;
    int high = INF;
    GetMinDistance(a - k, b - k, k, low, high);
    GetMinDistance(a + k, b + k, k, low, high);
    GetMinDistance(a - k, b + k, k, low, high);
    GetMinDistance(a + k, b - k, k, low, high);
    return {low, high};
}

int MinimizeDifferenceBetweenHeightsDP(vi arr, int k) {
    int n = arr.size();
    sort(arr);

    auto [low, high] = GetDistance(arr[0], arr[n - 1], k);

    for (int i = 1; i < n - 1; ++i) {
        int a = arr[i] - k;
        int b = arr[i] + k;

        if (a < 0) {
            high = b;
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
