#include "../../template.hpp"

int HammingDistance(vi arr1, vi arr2) {
    int n = arr1.size();
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr1[i] != arr2[i]) {
            ++count;
        }
    }
    return count;
}

int MaxHammingDistance(vi arr1) {
    int n = arr1.size();
    vi arr2 = arr1;
    int ans = 0;
    while (n-- > 0) {
        ans = max(ans, HammingDistance(arr1, arr2));
        rotate(arr2.begin(), arr2.begin() + 1, arr2.end());
    }
    return ans;
}

int HammingDistance2(vi arr, int j, int n) {
    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] != arr[(j + i) % n]) {
            ++count;
        }
    }
    return count;
}

int MaxHammingDistance2(vi arr) {
    int n = arr.size();
    int ans = 0;
    for (int j = 0; j < n; ++j) {
        ans = max(ans, HammingDistance2(arr, j, n));
    }
    return ans;
}

int main() { TimeMeasure _;
    vi arr1 = {1, 4, 1};
    vi arr2 = {2, 4, 8, 0};

    cout << MaxHammingDistance(arr1) << '\n'; // Ot(n^2), Om(n)
    cout << MaxHammingDistance(arr2) << '\n';
    cout << '\n';
    cout << MaxHammingDistance2(arr1) << '\n'; // Ot(n^2), Om(1)
    cout << MaxHammingDistance2(arr2) << '\n';
}
