#include "../../template.hpp"

bool SumOfTwoInSortedAndRotated(vi arr, int sum) {
    unordered_set<int> tab;
    for (int elem : arr) {
        tab.insert(elem);
    }
    for (int elem : arr) {
        if (tab.count(sum - elem)) {
            return true;
        }
    }
    return false;
}

bool SumOfTwoInSortedAndRotated2(vi arr, int sum) {
    int n = arr.size();
    int low = 0;
    int high = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[i] < arr[i - 1]) {
            high = i - 1;
            low = i;
        }
    }
    while (low != high) {
        int current = arr[low] + arr[high];
        if (current == sum) {

            return true;
        }
        else if (current < sum) {
            low = (low + 1) % n;
        }
        else {
            high = (high + n - 1) % n;
        }
    }
    return false;
}

int main() { TimeMeasure _;
    vi arr1 = {11, 15, 6, 8, 9, 10}; int sum1 = 16;
    vi arr2 = {11, 15, 26, 38, 9, 10}; int sum2 = 35;
    vi arr3 = {11, 15, 26, 38, 9, 10}; int sum3 = 45;
    cout << SumOfTwoInSortedAndRotated(arr1, sum1) << '\n'; // yes // hash
    cout << SumOfTwoInSortedAndRotated(arr2, sum2) << '\n'; // yes
    cout << SumOfTwoInSortedAndRotated(arr3, sum3) << '\n'; // no
    cout << '\n';
    cout << SumOfTwoInSortedAndRotated2(arr1, sum1) << '\n'; // yes // two pointers
    cout << SumOfTwoInSortedAndRotated2(arr2, sum2) << '\n'; // yes
    cout << SumOfTwoInSortedAndRotated2(arr3, sum3) << '\n'; // no
}
