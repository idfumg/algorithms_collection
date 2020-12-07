#include "../../template.hpp"

vi GetSums(vi arr, int from, int n, int total) {
    vi sums;
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += arr[from + j];
            }
        }
        if (sum <= total) {
            sums.push_back(sum);
        }
    }
    return sums;
}

int LowerBound(vi arr, int key) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low != high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key) low = mid + 1;
        else high = mid;
    }
    return low;
}

int MaxSumSubsetLessThanS(vi arr, int sum) {
    int n = arr.size();

    vi left = GetSums(arr, 0, n / 2, sum);
    vi right = GetSums(arr, n / 2, n - n / 2, sum);
    sort(right.begin(), right.end());

    int ans = -INF;
    for (int i = 0; i < left.size(); ++i) {
        int j = LowerBound(right, sum - left[i]);
        if (left[i] + right[j] == sum) {
            return sum;
        }
        if (j > 0 and left[i] + right[j - 1] <= sum) {
            ans = max(ans, left[i] + right[j - 1]);
        }
    }

    return ans;
}

int main() { TimeMeasure _;
    cout << MaxSumSubsetLessThanS({45, 34, 4, 12, 5, 2}, 42) << '\n'; // 41
    cout << MaxSumSubsetLessThanS({3, 34, 4, 12, 5, 2}, 10) << '\n'; // 10
}
