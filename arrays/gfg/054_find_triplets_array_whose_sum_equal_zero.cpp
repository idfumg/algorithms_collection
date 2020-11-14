#include "../../template.hpp"

void rec(vi arr, int n, vi elems) {
    if (elems.size() == 3) {
        if (elems[0] + elems[1] + elems[2] == 0) {
            cout << elems << '\n';
        }
        return;
    }
    if (n == 0) {
        return;
    }
    rec(arr, n - 1, elems);
    rec(arr, n - 1, elems + arr[n - 1]);
}

void rec(vi arr) {
    debugn(arr);
    rec(arr, arr.size(), {});
    cout << '\n';
}

void FindTriplets(vi arr) {
    debugn(arr);
    sort(arr.begin(), arr.end());
    int n = arr.size();
    for (int k = 0; k < n; ++k) {
        int i = k + 1;
        int j = n - 1;
        while (i < j) {
            if (i == k) {
                ++i;
                continue;
            }
            if (j == k) {
                --j;
                continue;
            }
            int sum = arr[i] + arr[j];
            if (sum + arr[k] == 0) {
                cout << arr[k] << ' ' << arr[i] << ' ' << arr[j] << '\n';
                break;
            }
            else if (sum + arr[k] < 0) {
                ++i;
            }
            else {
                --j;
            }
        }
    }
    cout << '\n';
}

int main() { TimeMeasure _;
    rec({0, -1, 2, -3, 1});
    rec({1, -2, 1, 0, 5});

    FindTriplets({0, -1, 2, -3, 1});
    FindTriplets({1, -2, 1, 0, 5});
}
