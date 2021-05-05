#include "../../template.hpp"

void FindClosestPair(vi arr1, vi arr2, int x) {
    int m = arr1.size();
    int n = arr2.size();

    int i = 0;
    int j = n - 1;

    int ans = -INF;
    int a = 0;
    int b = n - 1;

    while (i < m and j >= 0) {
        int sum = arr1[i] + arr2[j];
        if (sum <= x) {
            if (sum > ans) {
                ans = sum;
                a = i;
                b = j;
            }
            ++i;
        }
        else {
            --j;
        }
    }

    cout << ans << ':' << arr1[a] << ' ' << arr2[b] << endl;
}

int main() { TimeMeasure _;
    FindClosestPair({1, 4, 5, 7}, {10, 20, 30, 40}, 32); // 31 // 1 and 30
    FindClosestPair({1, 4, 5, 7}, {10, 20, 30, 40}, 50); // 47 // 7 and 40
}
