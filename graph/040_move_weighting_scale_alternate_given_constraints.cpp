#include "../template.hpp"
#include "../collection/graph.hpp"
#include "../collection/tree_node.hpp"

bool rec(vi& arr, vi& elems, int steps, int prev, int diff) {
    if (steps == 0) return true;
    for (int i = 0; i < size(arr); ++i) {
        if (i != prev and arr[i] > diff) {
            elems.push_back(arr[i]);
            if (rec(arr, elems, steps - 1, i, arr[i] - diff)) return true;
            elems.pop_back();
        }
    }
    return false;
}

vi rec(vi& arr, int steps) {
    vi elems;
    rec(arr, elems, steps, -INF, 0);
    return elems;
}

int main() { TimeMeasure _;
    vi arr = {2, 3, 5, 6};
    int steps = 10;
    cout << rec(arr, steps) << endl;
}
