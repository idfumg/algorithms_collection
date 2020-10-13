#include "../template.hpp"

int MaximizeArraySum(vi arr, int k) {
    int n = arr.size(), ans = 0;
    sort(arr);
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0 and k > 0) {
            ans += -arr[i];
            --k;
        }
        else if (arr[i] == 0 and k > 0) {
            k = 0;
        }
        else if (arr[i] > 0 and k > 0) {
            ans += k & 1 ? -arr[i] : arr[i];
            k = 0;
        }
        else {
            ans += arr[i];
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    vi arr1 = {-2, 0, 5, -1, 2}; // 10
    vi arr2 = {9, 8, 8, 5}; // 20
    cout << MaximizeArraySum(arr1, 4) << '\n';
    cout << MaximizeArraySum(arr2, 3) << '\n';
}
