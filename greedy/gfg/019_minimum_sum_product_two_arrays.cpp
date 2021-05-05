#include "../../template.hpp"

int MinSumProduct(vi a, vi b, int k) {
    int n = a.size(), mini = INF, minpos = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        int x = a[i] + 2 * k;
        int y = a[i] - 2 * k;
        if (b[i] * x <= mini) {
            mini = b[i] * x;
            minpos = i;
        }
        if (b[i] * y <= mini) {
            mini = b[i] * y;
            minpos = i;
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i == minpos) {
            sum += mini;
        }
        else {
            sum += a[i] * b[i];
        }
    }
    return sum;
}

int MinSumProduct2(vi a, vi b, int k) {
    int n = a.size();
    int maxsum = 0;
    for (int i = 0; i < n; ++i) {
        maxsum += a[i] * b[i];
    }
    int minsum = maxsum;
    for (int i = 0; i < n; ++i) {
        int decrease = (maxsum - a[i] * b[i] + (a[i] + 2 * k) * b[i]);
        int increase = (maxsum - a[i] * b[i] + (a[i] - 2 * k) * b[i]);
        minsum = min({minsum, decrease, increase});
    }
    return minsum;
}

int main() { TimeMeasure _;
    cout << MinSumProduct({1, 2, -3}, {-2, 3, -5}, 5) << '\n'; // -31
    cout << MinSumProduct({2, 3, 4, 5, 4}, {3, 4, 2, 3, 2}, 3) << '\n'; // 25
    cout << MinSumProduct({3, 2, 4, 5, 4}, {4, 3, 2, 3, 2}, 3) << '\n'; // 25
    cout << MinSumProduct({6,1,3,-4,-2,0}, {1,2,-3,-1,6,1}, 3) << '\n'; // -45
    cout << '\n';
    cout << MinSumProduct2({1, 2, -3}, {-2, 3, -5}, 5) << '\n'; // -31
    cout << MinSumProduct2({2, 3, 4, 5, 4}, {3, 4, 2, 3, 2}, 3) << '\n'; // 25
    cout << MinSumProduct2({3, 2, 4, 5, 4}, {4, 3, 2, 3, 2}, 3) << '\n'; // 25
    cout << MinSumProduct2({6,1,3,-4,-2,0}, {1,2,-3,-1,6,1}, 3) << '\n'; // -45
}
