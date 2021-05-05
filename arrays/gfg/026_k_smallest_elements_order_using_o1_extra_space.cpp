#include "../../template.hpp"

void KSmallestElems(vi arr, int k) {
    int n = arr.size();
    for (int i = k; i < n; ++i) {
        int maxi = -INF, maxipos = INF;
        for (int j = 0; j < k; ++j) {
            if (arr[j] > maxi) {
                maxi = arr[j];
                maxipos = j;
            }
        }
        if (arr[i] < maxi) {
            arr[maxipos] = arr[i];
        }
    }
    for_each(arr.begin(), arr.begin() + k, [](int v){cout << v << ' ';}); cout << endl;
}

int main() { TimeMeasure _;
    vi arr1 = {4, 2, 6, 1, 5}; int k1 = 3; // 4 2 1
    vi arr2 = {4, 12, 16, 21, 25}; int k2 = 3; // 4, 12, 16

    KSmallestElems(arr1, k1); // O(nlogn) + Om(n)
    KSmallestElems(arr2, k2);
}
