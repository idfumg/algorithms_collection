#include "../../template.hpp"

int kadanes(vi arr) {
    for (int i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] + arr[i] > arr[i]) {
            arr[i] = arr[i - 1] + arr[i];
        }
    }
    return max(arr);
}

int tab(vi arr) {
    int min_prefix_sum = 0, res = -INF;
    vi prefixsum(arr.size());
    prefixsum[0] = arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        prefixsum[i] = prefixsum[i - 1] + arr[i];
    }
    for (int i = 0; i < arr.size(); ++i) {
        res = max(res, prefixsum[i] - min_prefix_sum);
        min_prefix_sum = min(min_prefix_sum, prefixsum[i]);
    }
    return res;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {-2, -3, 4, -1, -2, 1, 5, -3};
    vi arr2 = {4, -8, 9, -4, 1, -8, -1, 6};
    cout << kadanes(arr1) << endl; // 7
    cout << kadanes(arr2) << endl; // 9
    cout << tab(arr1) << endl; // 7
    cout << tab(arr2) << endl; // 9
}
