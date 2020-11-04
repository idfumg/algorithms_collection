#include "../../template.hpp"

bool SumOfTwoInSortedAndRotated(vi arr, int sum) {
    unordered_map<int, int> tab;
    for (int v : arr) {
        ++tab[v];
    }
    for (int v : arr) {
        int rem = sum - v;
        if (rem == v and tab.count(rem) > 1) {
            return true;
        }
        if (rem != v and tab.count(rem) > 0) {
            return true;
        }
    }
    return false;
}

bool SumOfTwoInSortedAndRotated2(vi arr, int sum) {
    int n = arr.size();
    int left = 0;
    int right = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) {
            left = i + 1;
            right = i;
            break;
        }
    }
    while (left != right) {
        if (arr[left] + arr[right] == sum) {
            return true;
        }
        else if (arr[left] + arr[right] < sum) {
            left = (left + 1) % n;
        }
        else {
            right = (right + n - 1) % n;
        }
    }
    return false;
}

int main() { TimeMeasure _;
    vi arr1 = {11, 15, 6, 8, 9, 10}; int sum1 = 16;
    vi arr2 = {11, 15, 26, 38, 9, 10}; int sum2 = 35;
    vi arr3 = {11, 15, 26, 38, 9, 10}; int sum3 = 45;

    cout << SumOfTwoInSortedAndRotated(arr1, sum1) << '\n'; // yes // hash
    cout << SumOfTwoInSortedAndRotated(arr1, 10) << '\n'; // no
    cout << SumOfTwoInSortedAndRotated(arr2, sum2) << '\n'; // yes
    cout << SumOfTwoInSortedAndRotated(arr3, sum3) << '\n'; // no
    cout << '\n';
    cout << SumOfTwoInSortedAndRotated2(arr1, sum1) << '\n'; // yes // two pointers
    cout << SumOfTwoInSortedAndRotated2(arr1, 10) << '\n'; // no
    cout << SumOfTwoInSortedAndRotated2(arr2, sum2) << '\n'; // yes
    cout << SumOfTwoInSortedAndRotated2(arr3, sum3) << '\n'; // no
}
