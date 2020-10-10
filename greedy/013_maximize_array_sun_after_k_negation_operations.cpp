#include "../template.hpp"

int MaximizeArraySum(vi arr, int K) {
    sort(arr);
    int k = K, n = arr.size();
    for (int i = 0; i < K; ++i) {
        if (arr[i] < 0) {
            arr[i] *= -1;
            --k;
        }
    }
    if (k > 0) {
        int minpos = 0, minvalue = INF;
        for (int i = 0; i < n; ++i) {
            if (minvalue < arr[i]) {
                minvalue = arr[i];
                minpos = i;
                if (minvalue == 0) {
                    break;
                }
            }
        }
        arr[minpos] *= (k & 1 ? -1 : 1);
    }
    return accumulate(arr.begin(), arr.end(), 0);
}

int main() { TimeMeasure _;
    vi arr1 = {-2, 0, 5, -1, 2}; // 10
    vi arr2 = {9, 8, 8, 5}; // 20
    cout << MaximizeArraySum(arr1, 4) << '\n';
    cout << MaximizeArraySum(arr2, 3) << '\n';
}
