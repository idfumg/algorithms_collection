#include "../template.hpp"

int MinimizeDifferenceBetweenHeightsDP(vi arr, int k) {
    sort(arr);
    int n = arr.size(), a = arr[0] + k, b = arr[n - 1] - k;
    if (a > b) swap(a, b);
    for (int i = 1; i < n - 1; ++i) {
        int x = arr[i] - k;
        int y = arr[i] + k;
        if (x >= a or y <= b) {
            continue;
        }
        if (b - x <= y - a) {
            a = x;
        }
        else {
            b = y;
        }
    }
    return min(arr[n - 1] - arr[0], b - a);
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
