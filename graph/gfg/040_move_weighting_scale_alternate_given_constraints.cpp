#include "../../template.hpp"

void rec2(vi& arr, int steps, vi elems, int left, int right, int previdx) {
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
                rec2(arr, steps - 1, elems + arr[i], left, right + arr[i], i);
            }
        }
        else if (left < right) {
            if (arr[i] + left > right) {
                rec2(arr, steps - 1, elems + arr[i], left + arr[i], right, i);
            }
        }
        else {
            rec2(arr, steps - 1, elems + arr[i], left + arr[i], right, i);
        }
    }
}

vi rec2(vi arr, int steps) {
    vi elems;
    rec2(arr, steps, elems, 0, 0, -1);
    return elems;
}

vi rec(vi arr, int steps, int i, int prev, int left, int right, vi path) {
    int n = arr.size();
    int m = path.size();

    if (m == steps) {
        return path;
    }

    if (i > n) {
        return {};
    }

    if (i == prev) {
        return rec(arr, steps, i + 1, prev, left, right, path);
    }

    if (left > right and right + arr[i - 1] > left) {
        return rec(arr, steps, 1, i, left, right + arr[i - 1], path + arr[i - 1]);
    }

    if (left < right and left + arr[i - 1] > right) {
        return rec(arr, steps, 1, i, left + arr[i - 1], right, path + arr[i - 1]);
    }

    if (left == right) {
        return rec(arr, steps, 1, i, left + arr[i - 1], right, path + arr[i - 1]);
    }

    return rec(arr, steps, i + 1, prev, left, right, path);
}

vi rec(vi arr, int steps) {
    return rec(arr, steps, 1, -1, 0, 0, {});
}

int findWeight(vi arr, int left, int right) {
    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        if (left + arr[i] > right) return arr[i];
    }
    return 0;
}

void rec3(vi arr, int k, int left, int right, vi& ans, vi& elems) {
    if (k == 0) {
        if (ans.empty()) ans = elems;
        return;
    }
    if (left == 0 and right == 0) {
        elems.push_back(arr[0]);
        rec3(arr, k - 1, left + arr[0], right, ans, elems);
    }
    else if (left < right) {
        int weight = findWeight(arr, left, right);
        elems.push_back(weight);
        rec3(arr, k - 1, left + weight, right, ans, elems);
    }
    else if (right < left) {
        int weight = findWeight(arr, right, left);
        elems.push_back(weight);
        rec3(arr, k - 1, left, right + weight, ans, elems);
    }
    else {
        assert(false);
    }
}

vi rec3(vi arr, int k) {
    sort(arr.begin(), arr.end());
    vi ans;
    vi elems;
    rec3(arr, k, 0, 0, ans, elems);
    return ans;
}

int main() { TimeMeasure _;
    cout << rec2({2, 3, 5, 6}, 10) << '\n'; // 2 3 2 3 5 6 5 3 2 3
    cout << rec2({7, 11}, 3) << '\n'; // 7 11 7
    cout << endl;
    cout << rec({2, 3, 5, 6}, 10) << '\n'; // 2 3 2 3 5 6 5 3 2 3
    cout << rec({7, 11}, 3) << '\n'; // 7 11 7
    cout << endl;
    cout << rec3({2, 3, 5, 6}, 10) << '\n'; // 2 3 2 2 2 2 2 2 2 2
    cout << rec3({7, 11}, 3) << '\n'; // 7 11 7
}
