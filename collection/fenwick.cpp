#include <bits/stdc++.h>

using namespace std;

void fenwick_init(vector<int>& tree, const vector<int>& arr) noexcept {
    const int n = arr.size();
    tree.clear();
    tree.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        tree[i] += arr[i - 1];
        if (const int parent = i + (i & -i); parent <= n) {
            tree[parent] += tree[i];
        }
    }
}

int fenwick_sum(const vector<int>& tree, int i) noexcept {
    int res = 0;
    for (; i > 0; i -= i & -i) {
        res += tree[i];
    }
    return res;
}

int fenwick_sum(const vector<int>& tree, const int i, const int j) noexcept {
    return fenwick_sum(tree, j) - fenwick_sum(tree, i - 1);
}

void fenwick_update(vector<int>& tree, int i, const int delta) noexcept {
    const int n = tree.size();
    for (; i < n; i += (i & -i)) {
        tree[i] += delta;
    }
}

void fenwick_update(vector<int>& tree, const int i, const int j, const int delta) noexcept {
    for (int idx = i; idx <= j; ++idx) {
        fenwick_update(tree, idx, delta);
    }
}

void fenwick_set(vector<int>& tree, const int i, const int value) noexcept {
    const int delta = value - fenwick_sum(tree, i, i);
    fenwick_update(tree, i, delta);
}

void fenwick_sums(const vector<int>& tree, const vector<pair<int, int>>& ranges) noexcept {
    for (const auto& [i, j] : ranges) {
        cout << fenwick_sum(tree, i, j) << ' ';
    }
    cout << endl;
}

int main() {
    static const vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    vector<int> tree;
    fenwick_init(tree, arr);
    fenwick_sums(tree, {{1, 2}, {1, 3}, {2, 4}, {4, 8}, {6, 6}}); // 3 6 9 32 6
    fenwick_update(tree, 1, 3);
    fenwick_sums(tree, {{1, 2}, {1, 3}, {2, 4}, {4, 8}, {6, 6}}); // 6 9 9 32 6
    fenwick_update(tree, 1, 4, -1);
    fenwick_sums(tree, {{1, 2}, {1, 3}, {2, 4}, {4, 8}, {6, 6}}); // 4 6 6 31 6
    fenwick_set(tree, 6, 100);
    fenwick_sums(tree, {{1, 2}, {1, 3}, {2, 4}, {4, 8}, {6, 6}}); // 4 6 6 125 100
    return 0;
}
