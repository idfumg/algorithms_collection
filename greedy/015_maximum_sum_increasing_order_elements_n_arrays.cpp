#include "../template.hpp"

int MaximumSumWithIncreasingOrder(vvi arr) {
    int m = arr.size();
    for (int i = 0; i < m; ++i) {
        if (arr[i].empty()) return 0;
        sort(arr[i]);
    }
    int sum = 0, last = INF;
    for (int i = m - 1; i >= 0; --i) {
        int n = arr[i].size();
        for (int j = n - 1; j >= 0; --j) {
            if (arr[i][j] < last) {
                last = arr[i][j];
                sum += last;
                break;
            }
            else if (j == 0) { // can't find feasible element on that row
                return 0;
            }
        }
    }
    return sum;
}

int MaximumSumWithIncreasingOrder2(vvi arr) {
    int m = arr.size(), sum = 0, last = INF;
    for (int i = m - 1; i >= 0; --i) {
        if (arr[i].empty()) return 0;
        int n = arr[i].size(), maxi = -INF;
        for (int j = n - 1; j >= 0; --j) {
            if (arr[i][j] < last) {
                maxi = max(maxi, arr[i][j]);
            }
        }
        if (maxi == -INF) { // there isn't feasible element which is less than last
            return 0;
        }
        last = maxi;
        sum += last;
    }
    return sum;
}

int main() { TimeMeasure _;
    vvi arr1 = {{1, 7, 3, 4},
                {4, 2, 5, 1},
                {9, 5, 1, 8}};
    vvi arr2 = {{9, 8, 7},
                {6, 5, 4},
                {3, 2, 1}};
    cout << MaximumSumWithIncreasingOrder(arr1) << '\n'; // 18
    cout << MaximumSumWithIncreasingOrder(arr2) << '\n'; // 0
    cout << '\n';
    cout << MaximumSumWithIncreasingOrder2(arr1) << '\n'; // 18
    cout << MaximumSumWithIncreasingOrder2(arr2) << '\n'; // 0
}
