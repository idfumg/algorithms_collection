#include "../../template.hpp"

vi FindLeastAverage(vi arr, int k) {
    int n = arr.size();

    vi presum(n + 1);
    for (int i = 1; i <= n; ++i) {
        presum[i] = presum[i - 1] + arr[i - 1];
    }

    int idx = 0;
    int mini = INF;
    for (int i = k; i <= n; ++i) {
        int avg = (presum[i] - presum[i - k]) / k;

        if (mini > avg) {
            mini = avg;
            idx = i - k;
        }
    }

    vi ans;
    for (int i = idx; i < idx + k; ++i) {
        ans.push_back(arr[i]);
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << FindLeastAverage({3, 7, 90, 20, 10, 50, 40}, 3) << '\n';
    cout << FindLeastAverage({3, 7, 5, 20, -10, 0, 12}, 2) << '\n';
}
