#include "../../template.hpp"

void rec(vi arr, int k, int n, int mini, int maxi, int& diff) {
    if (n == 0) {
        if (mini >= 0 and maxi >= 0) {
            diff = min(diff, abs(maxi - mini));
        }
        return;
    }

    rec(arr, k, n - 1, min(mini, arr[n - 1] + k), max(maxi, arr[n - 1] + k), diff);
    rec(arr, k, n - 1, min(mini, arr[n - 1] - k), max(maxi, arr[n - 1] - k), diff);
}

int rec(vi arr, int k) {
    int diff = INF;
    rec(arr, k, arr.size(), INF, -INF, diff);
    return diff;
}

int rec2(vi arr, int k, int n, int mini, int maxi) {
    if (mini < 0) return INF;
    if (n == 0) return maxi - mini;
    return min(rec2(arr, k, n - 1, min(mini, arr[n - 1] + k), max(maxi, arr[n - 1] + k)),
               rec2(arr, k, n - 1, min(mini, arr[n - 1] - k), max(maxi, arr[n - 1] - k)));
}

int rec2(vi arr, int k) {
    return rec2(arr, k, arr.size(), INF, -INF);
}

int tab(vi arr, int k) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int ans = arr[n - 1] - arr[0];
    for (int i = 0; i < n - 1; ++i) {
        int mini = min(arr[0] + k, arr[i + 1] - k);
        int maxi = max(arr[i] + k, arr[n - 1] - k);
        ans = min(ans, maxi - mini);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 15, 10}; int k1 = 6;
    vi arr2 = {1, 5, 15, 10}; int k2 = 3;
    vi arr3 = {4, 6}; int k3 = 10;
    vi arr4 = {6, 10}; int k4 = 3;
    vi arr5 = {1, 10, 14, 14, 14, 15}; int k5 = 6;
    vi arr6 = {1, 2, 3}; int k6 = 2;

    cout << rec(arr1, k1) << '\n'; // 5
    cout << rec(arr2, k2) << '\n'; // 8
    cout << rec(arr3, k3) << '\n'; // 2
    cout << rec(arr4, k4) << '\n'; // 2
    cout << rec(arr5, k5) << '\n'; // 5
    cout << rec(arr6, k6) << '\n'; // 2
    cout << '\n';
    cout << rec2(arr1, k1) << '\n'; // 5
    cout << rec2(arr2, k2) << '\n'; // 8
    cout << rec2(arr3, k3) << '\n'; // 2
    cout << rec2(arr4, k4) << '\n'; // 2
    cout << rec2(arr5, k5) << '\n'; // 5
    cout << rec2(arr6, k6) << '\n'; // 2
    cout << '\n';
    cout << tab(arr1, k1) << '\n'; // 5
    cout << tab(arr2, k2) << '\n'; // 8
    cout << tab(arr3, k3) << '\n'; // 2
    cout << tab(arr4, k4) << '\n'; // 2
    cout << tab(arr5, k5) << '\n'; // 5
    cout << tab(arr6, k6) << '\n'; // 2
}
