#include "../../template.hpp"

bool naive(vi arr, vi& dep, int k) {
    int n = arr.size();
    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){return dep[i] < dep[j];});
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int count = 1;
        for (int j = i + 1; j < n; ++j) {
            if (arr[idx[j]] < dep[idx[i]]) {
                ++count;
            }
        }
        ans = max(ans, count);
    }
    return ans <= k;
}

bool FindKBookings(vi arr, vi& dep, int k) {
    int n = arr.size();
    vi idx(n);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j){return dep[i] < dep[j];});
    int ans = 1, count = 1, last = 0;
    for (int i = 1; i < n; ++i) {
        if (arr[idx[i]] < dep[last]) {
            ++count;
        }
        else {
            count = 1;
            last = i;
        }
        ans = max(ans, count);
    }
    return ans <= k;
}

int main() { TimeMeasure _;
    vi arr1[] = {{1,3,5},
                 {2,6,8}};
    vi arr2[] = {{1,2,3},
                 {2,3,4}};
    vi arr3[] = {{13,14,36,19,44,1,45,4,48,23,32,16,37,44,47,28,8,47,4,31,25,48,49,12,7,8},
                 {28,27,61,34,73,18,50,5,86,28,34,32,75,45,68,65,35,91,13,76,60,90,67,22,51,53}};

    cout << naive(arr1[0], arr1[1], 1) << '\n'; // false
    cout << naive(arr2[0], arr2[1], 1) << '\n'; // true
    cout << naive(arr3[0], arr2[1], 8) << '\n'; // true
    cout << '\n';
    cout << FindKBookings(arr1[0], arr1[1], 1) << '\n'; // false
    cout << FindKBookings(arr2[0], arr2[1], 1) << '\n'; // true
    cout << FindKBookings(arr3[0], arr2[1], 8) << '\n'; // true
}
