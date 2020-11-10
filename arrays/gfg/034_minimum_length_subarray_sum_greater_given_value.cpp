#include "../../template.hpp"

int tab(vi arr, int k) {
    int n = arr.size();
    vi presum(n + 1);
    for (int i = 1; i <= n; ++i) {
        presum[i] = presum[i - 1] + arr[i - 1];
    }

    int mini = INF;
    int minvalue = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            int value = presum[j] - presum[i - 1];
            if (value > k) {
                if (minvalue > value) {
                    minvalue = value;
                    mini = j - i + 1;
                }
            }
        }
    }
    return mini;
}

int tab2(vi arr, int k) { // Sliding Window
    int n = arr.size();
    int ans = 0;
    int count = INF;
    int left = 0;
    for (int i = 0; i < n; ++i) {
        if (ans <= k) {
            ans += arr[i];
            if (ans > k) {
                count = min(count, i - left);
            }
        }
        else {
            while (ans > k and left != i) {
                count = min(count, i - left);
                ans -= arr[left++];
            }
            ans += arr[i];
        }
    }
    if (ans > k) {
        return count;
    }
    return -1;
}

int main() { TimeMeasure _;
    // O(n^2)
    cout << tab({1, 4, 45, 6, 0, 19}, 51) << '\n'; // 3
    cout << tab({1, 10, 5, 2, 7}, 9) << '\n'; // 1
    cout << tab({1, 1, 5, 2, 7, 10}, 9) << '\n'; // 1
    cout << tab({1, 1, 10}, 9) << '\n'; // 1
    cout << tab({1, 11, 100, 1, 0, 200, 3, 2, 1, 250}, 280) << '\n'; // 4
    cout << tab({1, 2, 4}, 8) << '\n'; // -1
    cout << '\n';

    // O(n)
    cout << tab2({1, 4, 45, 6, 0, 19}, 51) << '\n'; // 3
    cout << tab2({1, 10, 5, 2, 7}, 9) << '\n'; // 1
    cout << tab({1, 1, 5, 2, 7, 10}, 9) << '\n'; // 1
    cout << tab({1, 1, 10}, 9) << '\n'; // 1
    cout << tab2({1, 11, 100, 1, 0, 200, 3, 2, 1, 250}, 280) << '\n'; // 4
    cout << tab2({1, 2, 4}, 8) << '\n'; // -1
}
