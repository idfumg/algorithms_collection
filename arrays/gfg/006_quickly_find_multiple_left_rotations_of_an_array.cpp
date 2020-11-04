#include "../../template.hpp"

void RotateSeveralTimes(vi arr, const vi& ks) {
    int n = arr.size();
    for (int k : ks) {
        vi temp = arr;
        if (k >= n) {
            k = k % n;
        }
        rotate(temp.begin(), temp.begin() + k, temp.end());
        cout << temp << '\n';
    }
    cout << '\n';
}

void RotateSeveralTimes2(vi elems, const vi& ks) {
    int n = elems.size();
    vi arr(2 * n);
    for (int i = 0; i < n; ++i) {
        arr[i] = elems[i];
        arr[i + n] = elems[i];
    }
    for (int k : ks) {
        int start = k % n;
        for (int i = start; i < start + n; ++i) {
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void RotateSeveralTimes3(vi arr, vi ks) {
    int n = arr.size();
    for (int k : ks) {
        for (int i = 0; i < n; ++i) {
            cout << arr[(i + k) % n] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() { TimeMeasure _;
    vi arr1 = {1, 3, 5, 7, 9};
    RotateSeveralTimes(arr1, {14});
    RotateSeveralTimes(arr1, {1, 3, 4, 6}); // straightforward O(n^2)
    cout << "-----------------" << '\n';
    RotateSeveralTimes2(arr1, {14});
    RotateSeveralTimes2(arr1, {1, 3, 4, 6}); // with additional space O(n), O(n)
    cout << "-----------------" << '\n';
    RotateSeveralTimes3(arr1, {14});
    RotateSeveralTimes3(arr1, {1, 3, 4, 6}); // without additional space O(n), O(1)
}
