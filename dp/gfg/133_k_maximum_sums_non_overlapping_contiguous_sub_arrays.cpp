#include "../../template.hpp"

vi tab(vi arr, int k) {
    int n = arr.size();
    vi ans;
    while (k--) {
        vi dp = arr;
        vi prev(n, -1);
        for (int i = 1; i < n; ++i) {
            if (arr[i] + dp[i - 1] > arr[i]) {
                dp[i] = arr[i] + dp[i - 1];
                prev[i] = i - 1;
            }
        }
        int maxsum = -INF;
        int maxidx = 0;
        for (int i = 0; i < n; ++i) {
            if (dp[i] > maxsum) {
                maxsum = dp[i];
                maxidx = i;
            }
        }
        ans.push_back(dp[maxidx]);
        for (int at = maxidx; at != -1; at = prev[at]) {
            arr[at] = -INF;
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 1, 1, -1, -3, -5, 6, 2, -6, -2}; int k1 = 3;
    vi arr2 = {5, 1, 2, -6, 2, -1, 3, 1}; int k2 = 2;
    cout << tab(arr1, k1) << endl; // 8 6 -1
    cout << tab(arr2, k2) << endl; // 8 5
}
