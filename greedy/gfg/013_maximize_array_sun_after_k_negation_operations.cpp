#include "../../template.hpp"

int MaximizeArraySum(vi arr, int k) {
    sort(arr);
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0 and k > 0) {
            arr[i] *= -1;
            --k;
        }
        else if (k > 0) {
            arr[i] *= k & 1 ? -1 : 1;
            k = 0;
        }
        ans += arr[i];
    }
    return ans;
}

int main() { TimeMeasure _;
    vi arr1 = {-2, 0, 5, -1, 2}; // 10
    vi arr2 = {9, 8, 8, 5}; // 20
    cout << MaximizeArraySum(arr1, 4) << '\n';
    cout << MaximizeArraySum(arr2, 3) << '\n';
}
