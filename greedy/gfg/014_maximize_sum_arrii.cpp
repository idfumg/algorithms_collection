#include "../../template.hpp"

int MaximizeSum(vi arr) {
    int n = arr.size(), sum = 0;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; ++i) {
        sum += arr[i] * i;
    }
    return sum;
}

int main() { TimeMeasure _;
    vi arr1 = { 3, 5, 6, 1 }; // 31
    vi arr2 = { 19, 20 }; // 20
    cout << MaximizeSum(arr1) << '\n';
    cout << MaximizeSum(arr2) << '\n';
}
