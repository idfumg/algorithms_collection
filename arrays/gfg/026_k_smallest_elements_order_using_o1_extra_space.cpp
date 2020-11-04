#include "../../template.hpp"

void KSmallestElems(vi arr, int k) {
    int n = arr.size();
    unordered_map<int, int> position;
    for (int i = 0; i < n; ++i) {
        position[arr[i]] = i;
    }
    sort(arr.begin(), arr.end());
    sort(arr.begin(), arr.begin() + k, [&](int a, int b){return position[a] < position[b];});
    for_each(arr.begin(), arr.begin() + k, [](int v){cout << v << ' ';});
    cout << '\n';
}

void KSmallestElems2(vi arr, int k) { // with destroying non-related array values
    int n = arr.size();

    for (int i = k; i < n; ++i) {
        int maxi = -INF, maxpos = INF;
        for (int j = 0; j < k; ++j) {
            if (arr[j] > maxi) {
                maxi = arr[j];
                maxpos = j;
            }
        }

        if (arr[i] < maxi) {
            arr[maxpos] = arr[i];
            arr[i] = INF;
        }
    }

    for (int i = 0; i < k; ++i) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {4, 2, 6, 1, 5}; int k1 = 3;
    vi arr2 = {4, 12, 16, 21, 25}; int k2 = 3;

    KSmallestElems(arr1, k1); // O(nlogn) + Om(n)
    KSmallestElems(arr2, k2);
    cout << '\n';
    KSmallestElems2(arr1, k1); // O(n) + Om(1)
    KSmallestElems2(arr2, k2);
}
