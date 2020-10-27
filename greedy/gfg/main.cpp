#include "../../template.hpp"

void rec(vi arr, int k, int n, int& ans, vi& elems) {
    if (n == 0) {
        int mini = *min_element(elems.begin(), elems.end());
        int maxi = *max_element(elems.begin(), elems.end());
        ans = min(ans, maxi - mini);
        return;
    }
    elems.push_back(arr[n - 1] + k);
    rec(arr, k, n - 1, ans, elems);
    elems.pop_back();

    elems.push_back(arr[n - 1] - k);
    rec(arr, k, n - 1, ans, elems);
    elems.pop_back();
}

int rec(vi arr, int k) {
    int n = arr.size();
    int ans = INF;
    vi elems;
    rec(arr, k, n, ans, elems);
    return ans;
}

int rec2(vi arr, int k, int n, vi& elems) {
    if (n == 0) {
        int mini = *min_element(elems.begin(), elems.end());
        int maxi = *max_element(elems.begin(), elems.end());
        return maxi - mini;
    }
    elems.push_back(arr[n - 1] + k);
    int a = rec2(arr, k, n - 1, elems);
    elems.pop_back();

    elems.push_back(arr[n - 1] - k);
    int b = rec2(arr, k, n - 1, elems);
    elems.pop_back();

    return min(a, b);
}

int rec2(vi arr, int k) {
    vi elems;
    return rec2(arr, k, arr.size(), elems);
}

int rec3(vi arr, int k, int n, int mini, int maxi) {
    if (n == 0) {
        return abs(maxi - mini);
    }
    return min(rec3(arr, k, n - 1, min(mini, arr[n - 1] - k), max(maxi, arr[n - 1] - k)),
               rec3(arr, k, n - 1, min(mini, arr[n - 1] + k), max(maxi, arr[n - 1] + k)));
}

int rec3(vi arr, int k) {
    vi elems;
    return rec3(arr, k, arr.size(), INF, -INF);
}

void FindMinDiff(int& x, int& y, int a, int b) {
    if (abs(a - b) < abs(x - y)) {
        x = a;
        y = b;
    }
}

pair<int, int> FindMinDiff(int a, int b, int k) {
    int x = -INF;
    int y = INF;
    FindMinDiff(x, y, a + k, b + k);
    FindMinDiff(x, y, a - k, b - k);
    FindMinDiff(x, y, a + k, b - k);
    FindMinDiff(x, y, a - k, b + k);
    return {min(x, y), max(x, y)};
}

void FindMinimumPossibleMaxDiff(int& low, int& high, int a, int b) {
    if (a >= low or b <= high or a < 0) {
        return;
    }
    int diff1 = high - a;
    int diff2 = b - low;
    if (diff1 <= diff1) {
        low = a;
    }
    else {
        high = b;
    }
}

int MinimizeDifferenceBetweenHeights(vi arr, int k) {
    sort(arr);
    int n = arr.size();
    auto [low, high] = FindMinDiff(arr[0], arr[n - 1], k);
    for (int i = 1; i < n - 1; ++i) {
        int a = arr[i] - k;
        int b = arr[i] + k;
        FindMinimumPossibleMaxDiff(low, high, a, b);
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
    cout << rec3(arr1, k1) << '\n'; // 5
    cout << rec3(arr2, k2) << '\n'; // 8
    cout << rec3(arr3, k3) << '\n'; // 2
    cout << rec3(arr4, k4) << '\n'; // 2
    cout << rec3(arr5, k5) << '\n'; // 5
    cout << rec3(arr6, k6) << '\n'; // 2
    cout << '\n';
    cout << MinimizeDifferenceBetweenHeights(arr1, k1) << '\n'; // 5
    cout << MinimizeDifferenceBetweenHeights(arr2, k2) << '\n'; // 8
    cout << MinimizeDifferenceBetweenHeights(arr3, k3) << '\n'; // 2
    cout << MinimizeDifferenceBetweenHeights(arr4, k4) << '\n'; // 2
    cout << MinimizeDifferenceBetweenHeights(arr5, k5) << '\n'; // 5
    cout << MinimizeDifferenceBetweenHeights(arr6, k6) << '\n'; // 2
}
