#include "../../template.hpp"

void FindAllSums(vi arr, int i, int j, int current, vi& sums, int sum) {
    if (current == j) {
        sums.push_back(sum);
        return;
    }
    for (int k = current; k < j; ++k) {
        FindAllSums(arr, i, j, k + 1, sums, sum);
        FindAllSums(arr, i, j, k + 1, sums, sum + arr[k]);
    }
}

vi FindAllSums(vi arr, int i, int j) {
    vi sums;
    FindAllSums(arr, i, j, i, sums, 0);
    sort(sums.begin(), sums.end());
    sums.resize(distance(sums.begin(), unique(sums.begin(), sums.end())));
    return sums;
}

vi FindAllSums2(vi& arr, int from, int n, int maximum) {
    vi sums;
    for (int i = 0; i < (1 << n); ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                sum += arr[from + j];
            }
        }
        if (sum <= maximum) {
            sums.push_back(sum);
        }
    }
    return sums;
}

int BinarySearch(int x, vi& arr, int total) {
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (x + arr[mid] == total) {
            return mid;
        }
        else if (x + arr[mid] < total and mid + 1 <= right and x + arr[mid + 1] > total) {
            return mid;
        }
        else if (x + arr[mid] > total) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int MaxSumSubsetLessThanS(vi arr, int total) {
    int n = arr.size();

    if (n == 0) return 0;
    if (n == 1) return arr[0];

    vi left = FindAllSums2(arr, 0, n / 2, total);
    vi right = FindAllSums2(arr, n / 2, n - n / 2, total);
    sort(right.begin(), right.end());

    int ans = 0;
    for (int i = 0; i < static_cast<int>(left.size()); ++i) {
        int idx = BinarySearch(left[i], right, total);
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
