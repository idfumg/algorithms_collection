#include "../../template.hpp"

void MaxiAndMinsOfAllSubarrays(vi arr, int K) {
    int n = arr.size();
    vvi maxs(n, vi(n));
    vvi mins(n, vi(n));
    for (int i = 1; i < n; ++i) {
        maxs[i - 1][i] = max(arr[i - 1], arr[i]);
        mins[i - 1][i] = min(arr[i - 1], arr[i]);
    }
    for (int k = 2; k < K; ++k) {
        for (int i = 0, j = i + k; j < n; ++i, ++j) {
            maxs[i][j] = max(maxs[i][j - 1], arr[j]);
            mins[i][j] = min(mins[i][j - 1], arr[j]);
        }
    }
    int ans = 0;
    for (int i = 0, j = K - 1; j < n; ++i, ++j) {
        ans += maxs[i][j] + mins[i][j];
    }
    cout << ans << endl;
}

int main() { TimeMeasure _;
    MaxiAndMinsOfAllSubarrays({2, 5, -1, 7, -3, -1, -2}, 4); // O(nk)
}
