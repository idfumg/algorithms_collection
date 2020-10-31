#include "../../template.hpp"

int GetSum(vi& arr) {
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += i * arr[i];
    }
    return ans;
}

int FindMaxSum(vi arr) {
    int ans = 0;
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        rotate(arr.begin(), arr.begin() + 1, arr.end());
        ans = max(ans, GetSum(arr));
    }
    return ans;
}

int main() { TimeMeasure _;
    vi arr1 = {1, 20, 2, 10}; // 72
    vi arr2 = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // 330
    vi arr3 = {8, 3, 1, 2}; // 29
    vi arr4 = {3, 2, 1}; // 7
    cout << FindMaxSum(arr1) << '\n';
    cout << FindMaxSum(arr2) << '\n';
    cout << FindMaxSum(arr3) << '\n';
    cout << FindMaxSum(arr4) << '\n';
}
