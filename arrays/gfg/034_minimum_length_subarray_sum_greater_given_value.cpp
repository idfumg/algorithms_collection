#include "../../template.hpp"

int SmallestSubarrayWithGreaterSum(vi arr, int key) {
    int n = arr.size();
    int window = 0;
    int windowsize = 0;
    int ans = INF;
    for (int i = 0; i < n; ++i) {
        if (window <= key) {
            window += arr[i];
            windowsize += 1;
        }
        while (window > key) {
            ans = min(ans, windowsize + 1);
            window -= arr[i - windowsize];
            windowsize -= 1;
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << SmallestSubarrayWithGreaterSum({1, 4, 45, 6, 0, 19}, 51) << '\n'; // 3
    cout << SmallestSubarrayWithGreaterSum({1, 10, 5, 2, 7}, 9) << '\n'; // 1
    cout << SmallestSubarrayWithGreaterSum({1, 1, 5, 2, 7, 10}, 9) << '\n'; // 1
    cout << SmallestSubarrayWithGreaterSum({1, 1, 10}, 9) << '\n'; // 1
    cout << SmallestSubarrayWithGreaterSum({10, 1, 2}, 9) << '\n'; // 1
    cout << SmallestSubarrayWithGreaterSum({1, 11, 100, 1, 0, 200, 3, 2, 1, 250}, 280) << '\n'; // 4
    cout << SmallestSubarrayWithGreaterSum({1, 2, 4}, 8) << '\n'; // -1
}
