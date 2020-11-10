#include "../../template.hpp"

int FindMaxAvgSubarray(vi arr, int k) {
    int n = arr.size();
    int sum = 0;
    int maxsum = 0;
    int i = 0;
    int j = 0;

    while (j < k) {
        sum += arr[j++];
    }
    maxsum = max(maxsum, sum);

    for (; j < n; ++j) {
        sum -= arr[i++];
        sum += arr[j];
        maxsum = max(maxsum, sum);
    }

    return maxsum;
}

int main() { TimeMeasure _;
    cout << FindMaxAvgSubarray({1, 12, -5, -6, 50, 3}, 4) << '\n'; // 51
}
