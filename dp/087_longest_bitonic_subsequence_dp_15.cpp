#include "../template.hpp"

int tab(vi& arr) {
    const int n = arr.size();
    vi LIS(n, 1), LDS(n, 1);

    for (int i = 0; i < n; ++i) { // find LIS
        for (int j = 0; j < i; ++j) {
            if (arr[j] < arr[i]) LIS[i] = max(LIS[i], LIS[j] + 1);
        }
    }

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) LDS[i] = max(LDS[i], LDS[j] + 1);
        }
    }

    debug(LIS); debug(LDS);

    const int maxi1 = max(LIS), maxi2 = max(LDS);
    int res = 0, lispos = 0, ldspos = 0;
    deque<int> elems;

    if (maxi1 > maxi2) {
        for (int i = n - 1; i >= 0; --i) {
            if (LIS[i] == maxi1) {
                res = maxi1 + (i != n - 1 ? LDS[i + 1] : 0);
                lispos = i;
                ldspos = i + 1 != n ? (i + 1) : -1;
                int k = LIS[i];
                for (int j = i; j >= 0; --j) {
                    if (LIS[j] == k) {
                        elems.push_back(arr[j]);
                        --k;
                    }
                }
                k = LDS[i];
                for (int j = i + 1; j < n; ++j) {
                    if (LDS[j] == k) {
                        elems.push_back(arr[j]);
                        --k;
                    }
                }
                debug(elems);
                break;
            }
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (LDS[i] == maxi2) {
                res = maxi2 + (i != 0 ? LIS[i - 1] : 0);
                ldspos = i;
                lispos = i != 0 ? (i - 1) : -1;
                int k = LDS[i];
                for (int j = i; j < n; ++j) {
                    if (LDS[j] == k) {
                        elems.push_back(arr[j]);
                        --k;
                    }
                }
                k = LIS[i - 1];
                for (int j = i - 1; j >= 0; --j) {
                    if (LIS[j] == k) {
                        elems.push_front(arr[j]);
                        --k;
                    }
                }
                debug(elems);
                break;
            }
        }
    }

    return res;
}

int main() { TimeMeasure _; __x();
    vi arr1 = {1, 11, 2, 10, 4, 5, 2, 1};
    vi arr2 = {12, 11, 40, 5, 3, 1};
    vi arr3 = {80, 60, 30, 40, 20, 10};
    cout << tab(arr1) << endl;
    cout << tab(arr2) << endl;
    cout << tab(arr3) << endl;
}
