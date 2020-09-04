#include "../template.hpp"

int naive(vi& arr) { // O(n^2)
    int n = arr.size();
    int maxi = arr[1] - arr[0];
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] - arr[i] > maxi) {
                maxi = arr[j] - arr[i];
            }
        }
    }
    return maxi;
}

int fast(vi& arr) { // O(n)
    int n = arr.size(), min_element = arr[0], maxi = arr[1] - arr[0];
    for (int i = 1; i < n; ++i) {
        if (arr[i] - min_element > maxi) {
            maxi = arr[i] - min_element;
        }
        if (arr[i] < min_element) {
            min_element = arr[i];
        }
    }
    return maxi;
}

int tricky(vi& arr) { // O(n)
    int n = arr.size();
    vi diffs(n);
    for (int i = 0; i < n - 1; ++i) {
        diffs[i] = arr[i + 1] - arr[i];
    }
    int max_diff = diffs[0];
    for (int i = 1; i < n - 1; ++i) {
        if (diffs[i - 1] > 0) {
            diffs[i] += diffs[i - 1];
        }
        if (max_diff < diffs[i]) {
            max_diff = diffs[i];
        }
    }
    return max_diff;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 2, 90, 10, 110};
    vi arr2 = {80, 2, 6, 3, 100};
    vi arr3 = {10, 1};
    vi arr4 = {2, -1, 5, -6, 3};
    cout << naive(arr1) << endl; // 109
    cout << naive(arr2) << endl; // 98
    cout << naive(arr3) << endl; // -9
    cout << naive(arr4) << endl; // 9
    cout << fast(arr1) << endl; // 109
    cout << fast(arr2) << endl; // 98
    cout << fast(arr3) << endl; // -9
    cout << fast(arr4) << endl; // 9
    cout << tricky(arr1) << endl; // 109
    cout << tricky(arr2) << endl; // 98
    cout << tricky(arr3) << endl; // -9
    cout << tricky(arr4) << endl; // 9
}
