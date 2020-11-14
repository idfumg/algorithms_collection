#include "../../template.hpp"

void FindClosestPair(vi arr1, vi arr2, int key) {
    int m = arr1.size();
    int n = arr2.size();
    int i = 0;
    int j = n - 1;
    int maxi = 0;
    int elem1 = 0;
    int elem2 = 0;
    while (i < m and j < n) {
        int sum = arr1[i] + arr2[j];
        if (sum <= key) {
            if (sum > maxi) {
                maxi = sum;
                elem1 = i;
                elem2 = j;
            }
            ++i;
        }
        else {
            --j;
        }
    }
    cout << arr1[elem1] << ' ' << arr2[elem2] << '\n';
}

int main() { TimeMeasure _;
    FindClosestPair({1, 4, 5, 7}, {10, 20, 30, 40}, 32);
    FindClosestPair({1, 4, 5, 7}, {10, 20, 30, 40}, 50);
}
