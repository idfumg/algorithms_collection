#include "../template.hpp"

// Explanation:
// https://github.com/Dedalus-Stephen/Traders-Max-Profit

int find_max_diff(vi& arr, int from, int to) {
    int max_diff = 0, min_element = arr[from];
    for (int j = from; j < to; ++j) {
        if (arr[j] - min_element > max_diff) {
            max_diff = arr[j] - min_element;
        }
        if (min_element > arr[j]) {
            min_element = arr[j];
        }
    }
    return max_diff;
}

int naive(vi& arr) {
    int n = arr.size(), profit = 0;
    for (int i = 0; i < n; ++i) {
        int max_diff1 = find_max_diff(arr, 0, i);
        int max_diff2 = find_max_diff(arr, i, n);
        profit = max(profit, max_diff1 + max_diff2);
    }
    return profit;
}

int fast(vi& arr) {
    int n = arr.size(), maxi = arr[n - 1], mini = arr[0];
    vi profit(n);
    for (int i = n - 2; i >= 0; --i) {
        if (arr[i] > maxi) maxi = arr[i];
        profit[i] = max(profit[i + 1], maxi - arr[i]);
    }
    for (int i = 1; i < n; ++i) {
        if (arr[i] < mini) mini = arr[i];
        profit[i] = max(profit[i - 1], profit[i] + arr[i] - mini);
    }
    return profit[n - 1];
}

int main() { TimeMeasure _; __x();
    vi arr1 = {10, 22, 5, 75, 65, 80};
    vi arr2 = {2, 30, 15, 10, 8, 25, 80};
    vi arr3 = {100, 30, 15, 10, 8, 25, 80};
    vi arr4 = {90, 80, 70, 60, 50};
    vi arr5 = {75, 4, 25, 20, 60, 45};
    vi arr6 = {40, 5, 80, 20, 60};
    cout << naive(arr1) << endl;
    cout << naive(arr2) << endl;
    cout << naive(arr3) << endl;
    cout << naive(arr4) << endl;
    cout << naive(arr5) << endl;
    cout << naive(arr6) << endl;
    cout << endl;
    cout << fast(arr1) << endl;
    cout << fast(arr2) << endl;
    cout << fast(arr3) << endl;
    cout << fast(arr4) << endl;
    cout << fast(arr5) << endl;
    cout << fast(arr6) << endl;
}
