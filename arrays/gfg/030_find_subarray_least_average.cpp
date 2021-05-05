#include "../../template.hpp"

void FindLeastAverage(vi arr, int k) {
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

    for (int i = idx; i < idx + k; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void FindLeastAverage2(vi arr, int k) {
    int window = 0;
    for (int i = 0; i < k; ++i) {
        window += arr[i];
    }
    int miniavg = window;
    int from = 0;
    int n = arr.size();
    for (int i = k; i < n; ++i) {
        window = window - arr[i - k] + arr[i];
        if (miniavg > window / k) {
            miniavg = window / k;
            from = i - k + 1;
        }
    }
    for (int i = from; i < from + k; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

void FindLeastAverage3(vi arr, int k) {
    int n = arr.size();
    int avg = accumulate(arr.begin(), arr.begin() + k, 0);
    int minavg = avg / k;
    for (int i = k; i < n; ++i) {
        avg -= arr[i - k];
        avg += arr[i];
        minavg = min(minavg, avg / k);
    }
    cout << minavg << endl;
}


int main() { TimeMeasure _;
    FindLeastAverage({3, 7, 90, 20, 10, 50, 40}, 3);
    FindLeastAverage({3, 7, 5, 20, -10, 0, 12}, 2);
    cout << endl;
    FindLeastAverage2({3, 7, 90, 20, 10, 50, 40}, 3);
    FindLeastAverage2({3, 7, 5, 20, -10, 0, 12}, 2);
    cout << endl;
    FindLeastAverage3({3, 7, 90, 20, 10, 50, 40}, 3);
    FindLeastAverage3({3, 7, 5, 20, -10, 0, 12}, 2);
}
