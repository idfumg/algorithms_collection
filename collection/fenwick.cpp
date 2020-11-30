#include <bits/stdc++.h>

using namespace std;

vector<int> fenwick;

void fenwick_init(const vector<int>& arr) {
    const int n = arr.size() + 1;
    fenwick.resize(n);
    for (int i = 1; i <= n; ++i) {
        fenwick[i] += arr[i - 1];
        int parent = i + (i & -i);
        if (parent <= n) {
            fenwick[parent] += fenwick[i];
        }
    }
}

int fenwick_sum(int i) {
    int res = 0;
    for (; i > 0; i -= i & -i) {
        res += fenwick[i];
    }
    return res;
}

int fenwick_sum(const int l, const int r) {
    return fenwick_sum(r) - fenwick_sum(l - 1);
}

void fenwick_update(int i, int delta) {
    const int n = fenwick.size();
    for (; i <= n; i += i & -i) {
        fenwick[i] += delta;
    }
}

void fenwick_update(int i, int j, int delta) {
    fenwick_update(i, delta);
    fenwick_update(j + 1, -delta);
}

void fenwick_set(int i, int value) {
    int delta = value - fenwick_sum(i, i);
    fenwick_update(i, delta);
}

void prefix_sums(const vector<int>& arr, const vector<vector<int>>& ranges) {
    const int n = arr.size();
    vector<int> prefix(n + 1);
    for (int i = 1; i <= n; ++i) {
        prefix[i] = prefix[i - 1] + arr[i - 1];
    }
    for (const auto& range : ranges) {
        const int i = range[0];
        const int j = range[1];
        cout << prefix[j] - prefix[i - 1] << ' ';
    }
    cout << endl;
}

void fenwick_sums(const vector<int>& arr, const vector<vector<int>>& ranges) {
    fenwick_init(arr);
    for (const auto& range : ranges) {
        const int i = range[0];
        const int j = range[1];
        cout << fenwick_sum(i, j) << ' ';
    }
    cout << endl;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    prefix_sums(arr, {{1, 2}, {1, 3}, {2, 4}, {4, 8}});
    fenwick_sums(arr, {{1, 2}, {1, 3}, {2, 4}, {4, 8}});
    return 0;
}
