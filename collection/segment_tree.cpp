#include "../template.hpp"

void build(const vector<int>& arr, vector<int>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start - 1];
    }
    else {
        int mid = start + (end - start) / 2;
        build(arr, tree, 2 * node + 0, start, mid);
        build(arr, tree, 2 * node + 1, mid + 1, end);
        tree[node] = tree[2 * node + 0] + tree[2 * node + 1];
    }
}

int query(const vector<int>& tree, int node, int start, int end, int l, int r) {
    if (r < start or end < l) {
        return 0;
    }
    if (l <= start and end <= r) {
        return tree[node];
    }
    int mid = start + (end - start) / 2;
    int p1 = query(tree, 2 * node + 0, start, mid, l, r);
    int p2 = query(tree, 2 * node + 1, mid + 1, end, l, r);
    return p1 + p2;
}

void update(vector<int>& tree, int node, int start, int end, int idx, int value) {
    if (start == end) {
        tree[node] = value;
    }
    else {
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(tree, 2 * node, start, mid, idx, value);
        }
        else {
            update(tree, 2 * node + 1, mid + 1, end, idx, value);
        }
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }
}

vector<int> build2(const vector<int>& arr) {
    const int n = arr.size();
    vector<int> tree(2 * n);
    for (int i = 0; i < n; ++i) tree[n + i] = arr[i];
    for (int i = n - 1; i > 0; --i) tree[i] = tree[i << 1] + tree[i << 1 | 1];
    return tree;
}

int query2(const vector<int>& tree, int l, int r) {
    const int n = tree.size() / 2 - 1;
    int res = 0;
    for (l += n, r += n; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) res += tree[l++];
        if (!(r & 1)) res += tree[r--];
    }
    return res;
}

void update2(vector<int>& tree, int p, const int value) {
    const int n = tree.size() / 2 - 1;
    for (tree[p += n] = value; p > 1; p >>= 1) {
        tree[p >> 1] = tree[p] + tree[p ^ 1];
    }
}

int main() { TimeMeasure _;
    {
        const vector<int> arr = {1, 2, 3, 4};
        const int n = arr.size();

        vector<int> tree(2 * n);
        build(arr, tree, 1, 1, n);
        debugn(tree);

        cout << query(tree, 1, 1, n, 1, 4) << endl; // 10
        cout << query(tree, 1, 1, n, 1, 3) << endl; // 6
        cout << query(tree, 1, 1, n, 1, 2) << endl; // 3
        cout << query(tree, 1, 1, n, 1, 1) << endl; // 1
        cout << query(tree, 1, 1, n, 2, 4) << endl; // 9
        cout << query(tree, 1, 1, n, 3, 4) << endl; // 7
        cout << query(tree, 1, 1, n, 4, 4) << endl; // 4
        cout << query(tree, 1, 1, n, 2, 3) << endl; // 5

        update(tree, 1, 1, n, 3, 10);

        cout << query(tree, 1, 1, n, 1, 4) << endl; // 17
        cout << query(tree, 1, 1, n, 1, 3) << endl; // 13
        cout << query(tree, 1, 1, n, 3, 3) << endl; // 10
        cout << query(tree, 1, 1, n, 3, 4) << endl; // 14
    }
    cout << endl;
    {
        const vector<int> arr = {1, 2, 3, 4};
        vector<int> tree = build2(arr);
        debugn(tree);

        cout << query2(tree, 1, 4) << endl; // 10
        cout << query2(tree, 1, 3) << endl; // 6
        cout << query2(tree, 1, 2) << endl; // 3
        cout << query2(tree, 1, 1) << endl; // 1
        cout << query2(tree, 2, 4) << endl; // 9
        cout << query2(tree, 3, 4) << endl; // 7
        cout << query2(tree, 4, 4) << endl; // 4
        cout << query2(tree, 2, 3) << endl; // 5

        update2(tree, 3, 10);

        cout << query2(tree, 1, 4) << endl; // 17
        cout << query2(tree, 1, 3) << endl; // 13
        cout << query2(tree, 3, 3) << endl; // 10
        cout << query2(tree, 3, 4) << endl; // 14
    }
}
