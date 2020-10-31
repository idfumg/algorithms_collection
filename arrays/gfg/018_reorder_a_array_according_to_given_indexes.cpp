#include "../../template.hpp"

void ReorderByIndexes(vi arr, vi pos) {
    int n = arr.size();
    vi temp(n);
    for (int i = 0; i < n; ++i) {
        temp[pos[i]] = arr[i];
    }
    debugn(temp);
}

int main() { TimeMeasure _;
    ReorderByIndexes({10, 11, 12}, {1, 0, 2});
    ReorderByIndexes({50, 40, 70, 60, 90}, {3,  0,  4,  1,  2});
}
