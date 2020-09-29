#include "../template.hpp"

void rec(vi& arr, vi& elems, int steps, int left, int right, int prev) {
    int n = arr.size();
    if (steps == 0) {
        cout << elems << '\n';
        return;
    }
    if (left > right) {
        for (int i = 0; i < n; ++i) {
            if (i != prev) {
                if (right + arr[i] > left) {
                    elems.push_back(arr[i]);
                    rec(arr, elems, steps - 1, left, right + arr[i], i);
                    elems.pop_back();
                }
            }
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            if (i != prev) {
                if (left + arr[i] > right) {
                    elems.push_back(arr[i]);
                    rec(arr, elems, steps - 1, left + arr[i], right, i);
                    elems.pop_back();
                }
            }
        }
    }
}

vi rec(vi& arr, int steps) {
    int n = arr.size();
    vi elems;
    for (int i = 0; i < n; ++i) {
        rec(arr, elems, steps, arr[i], 0, i);
    }
    return elems;
}

int main() { TimeMeasure _;
    vi arr = {2, 3, 5, 6};
    int steps = 10;
    cout << rec(arr, steps) << '\n';
}
