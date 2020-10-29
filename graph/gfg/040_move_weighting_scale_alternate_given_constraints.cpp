#include "../../template.hpp"

void rec(vi& arr, int steps, vi& elems, int left, int right, int previdx) {
    if (steps == 0) {
        cout << elems << '\n';
        return;
    }
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        if (i == previdx) {
            continue;
        }
        else if (left > right) {
            if (arr[i] + right > left) {
                elems.push_back(arr[i]);
                rec(arr, steps - 1, elems, left, right + arr[i], i);
                elems.pop_back();
            }
        }
        else if (left < right) {
            if (arr[i] + left > right) {
                elems.push_back(arr[i]);
                rec(arr, steps - 1, elems, left + arr[i], right, i);
                elems.pop_back();
            }
        }
        else {
            elems.push_back(arr[i]);
            rec(arr, steps - 1, elems, left + arr[i], right, i);
            elems.pop_back();
        }
    }
}

vi rec(vi arr, int steps) {
    vi elems;
    rec(arr, steps, elems, 0, 0, -1);
    return elems;
}

int main() { TimeMeasure _;
    cout << rec({2, 3, 5, 6}, 10) << '\n'; // 3, 2, 3, 5, 6, 5, 3, 2, 3
    cout << rec({7, 11}, 3) << '\n'; // 7 11 7
}
