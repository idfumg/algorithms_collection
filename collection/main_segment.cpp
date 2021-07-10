#include <bits/stdc++.h>
#include "../template.hpp"

using namespace std;

static void segment_init(vector<int>& tree, const vector<int>& arr, const int node, const int left, const int right) noexcept {
    if (left == right) {
        tree[node] = arr[left - 1];
        return;
    }
    const int mid = left + (right - left) / 2;
    segment_init(tree, arr, 2 * node + 0, left, mid);
    segment_init(tree, arr, 2 * node + 1, mid + 1, right);
    tree[node] = tree[2 * node + 0] + tree[2 * node + 1];
}

static int segment_sum(const vector<int>& tree, const int node, const int left, const int right, const int from, const int to) noexcept {
    if (to < left or right < from) return 0;
    if (from <= left and right <= to) return tree[node];
    const int mid = left + (right - left) / 2;
    const int sum1 = segment_sum(tree, 2 * node + 0, left, mid, from, to);
    const int sum2 = segment_sum(tree, 2 * node + 1, mid + 1, right, from, to);
    return sum1 + sum2;
}

static void segment_update(vector<int>& tree, const int node, const int left, const int right, const int idx, const int value) noexcept {
    if (left == right) {
        tree[node] += value;
        return;
    }
    const int mid = left + (right - left) / 2;
    if (idx <= mid) segment_update(tree, 2 * node + 0, left, mid, idx, value);
    else segment_update(tree, 2 * node + 1, mid + 1, right, idx, value);
    tree[node] = tree[2 * node + 0] + tree[2 * node + 1];
}

static void segment_set(vector<int>& tree, const int node, const int left, const int right, const int idx, const int value) noexcept {
    if (left == right) {
        tree[node] = value;
        return;
    }
    const int mid = left + (right - left) / 2;
    if (idx <= mid) segment_set(tree, 2 * node + 0, left, mid, idx, value);
    else segment_set(tree, 2 * node + 1, mid + 1, right, idx, value);
    tree[node] = tree[2 * node + 0] + tree[2 * node + 1];
}

void segment_init(vector<int>& tree, const vector<int>& arr) noexcept {
    tree.resize(3 * arr.size());
    segment_init(tree, arr, 1, 1, arr.size());
}

int segment_sum(const vector<int>& tree, const int from, const int to) noexcept {
    return segment_sum(tree, 1, 1, tree.size() / 3, from, to);
}

void segment_update(vector<int>& tree, const int idx, const int value) noexcept {
    segment_update(tree, 1, 1, tree.size() / 3, idx, value);
}

void segment_update(vector<int>& tree, const int from, const int to, const int value) noexcept {
    for (int idx = from; idx <= to; ++idx) {
        segment_update(tree, idx, value);
    }
}

void segment_set(vector<int>& tree, const int idx, const int value) noexcept {
    segment_set(tree, 1, 1, tree.size() / 3, idx, value);
}

void segment_sums(const vector<int>& tree, const vector<pair<int, int>>& ranges) noexcept {
    for (const auto& [i, j] : ranges) {
        cout << segment_sum(tree, i, j) << ' ';
    }
    cout << endl;
}

int main() {
    static const vector<int> arr = {1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 12};
    vector<int> tree;
    segment_init(tree, arr);
    segment_sums(tree, {{1, 2}, {1, 3}, {2, 4}, {4, 8}, {6, 6}}); // 3 6 9 32 6
    segment_update(tree, 1, 3);
    segment_sums(tree, {{1, 2}, {1, 3}, {2, 4}, {4, 8}, {6, 6}}); // 6 9 9 32 6
    segment_update(tree, 1, 4, -1);
    segment_sums(tree, {{1, 2}, {1, 3}, {2, 4}, {4, 8}, {6, 6}}); // 4 6 6 31 6
    segment_set(tree, 6, 100);
    segment_sums(tree, {{1, 2}, {1, 3}, {2, 4}, {4, 8}, {6, 6}}); // 4 6 6 125 100
}
