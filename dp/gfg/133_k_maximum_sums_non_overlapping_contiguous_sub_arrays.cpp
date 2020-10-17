#include "../../template.hpp"

vi tab(vi arr, int K) {
    int n = arr.size();
    vvi res;
    vi sums;
    for (int k = 1; k <= K; ++k) {
        int maxi = -INF, maxipos = 0;
        vi prev(n, -1), dp = arr;
        for (int i = 1; i < n; ++i) {
            if (dp[i - 1] + arr[i] > dp[i]) {
                dp[i] = dp[i - 1] + arr[i];
                prev[i] = i - 1;
            }
            else {
                dp[i] = arr[i];
                prev[i] = -1;
            }
            if (dp[i] > maxi) {
                maxi = dp[i];
                maxipos = i;
            }
        }
        vi elems;
        for (int at = maxipos; at != -1; at = prev[at]) {
            elems.push_back(arr[at]);
            arr[at] = -INF;
        }
        reverse(elems);
        res.push_back(elems);
        sums.push_back(maxi);
    }
    debug(res);
    return sums;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {4, 1, 1, -1, -3, -5, 6, 2, -6, -2}; int k1 = 3;
    vi arr2 = {5, 1, 2, -6, 2, -1, 3, 1}; int k2 = 2;
    cout << tab(arr1, k1) << endl;
    cout << tab(arr2, k2) << endl;
}
