#include "../../template.hpp"

vi GetSums(vi arr, int from, int n, int total) {
    vi ans;
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += arr[from + j];
            }
        }
        if (sum <= total) {
            ans.push_back(sum);
        }
    }
    return ans;
}

int BinarySearch(vi arr, int key) {
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low != high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] < key) low = mid + 1;
        else high = mid;
    }
    return arr[low] == key ? low : low - 1;
}

int MaxSumSubsetLessThanS(vi arr, int total) {
    int n = arr.size();
    vi left = GetSums(arr, 0, n / 2, total);
    vi right = GetSums(arr, n / 2, n - n / 2, total);
    sort(right.begin(), right.end());
    int m = left.size();
    int ans = 0;
    for (int i = 0; i < m; ++i) {
        int idx = LowerBound(right, total - left[i]);
        if (idx != -1) {
            ans = max(ans, left[i] + right[idx]);
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << MaxSumSubsetLessThanS({45, 34, 4, 12, 5, 2}, 42) << '\n'; // 41
    cout << MaxSumSubsetLessThanS({3, 34, 4, 12, 5, 2}, 10) << '\n'; // 10
}
