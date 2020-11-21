#include "../../template.hpp"

int tab2(vi arr, int k) {
    int n = arr.size();
    int window = 0;
    int mincount = INF;
    int left = 0;
    int right = 0;
    while (left < n or right < n) {
        if (window <= k and right < n) {
            window += arr[right++];
        }
        else {
            window -= arr[left++];
        }
        if (window > k) {
            mincount = min(mincount, right - left);
        }
    }
    return mincount == INF ? -1 : mincount;
}

int main() { TimeMeasure _;
    cout << tab2({1, 4, 45, 6, 0, 19}, 51) << '\n'; // 3
    cout << tab2({1, 10, 5, 2, 7}, 9) << '\n'; // 1
    cout << tab2({1, 1, 5, 2, 7, 10}, 9) << '\n'; // 1
    cout << tab2({1, 1, 10}, 9) << '\n'; // 1
    cout << tab2({10, 1, 2}, 9) << '\n'; // 1
    cout << tab2({1, 11, 100, 1, 0, 200, 3, 2, 1, 250}, 280) << '\n'; // 4
    cout << tab2({1, 2, 4}, 8) << '\n'; // -1
}
