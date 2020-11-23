#include "../template.hpp"

void GenSubsetsRec(vi arr, size_t i, vi& subset) {
    if (i > arr.size()) {
        cout << subset << endl;
        return;
    }
    GenSubsetsRec(arr, i + 1, subset);
    subset.push_back(arr[i - 1]);
    GenSubsetsRec(arr, i + 1, subset);
    subset.pop_back();
}

void GenSubsetsRec(vi arr) {
    vi subset;
    return GenSubsetsRec(arr, 1, subset);
}

void GenSubsetsIter(vi arr) {
    for (size_t i = 0; i < (1 << arr.size()); ++i) {
        vi subset;
        for (size_t j = 0; j < arr.size(); ++j) {
            if (i & (1 << j)) {
                subset.push_back(arr[j]);
            }
        }
        cout << subset << endl;
    }
}

int main() { TimeMeasure _;
    GenSubsetsRec({1, 2, 6, 90, 0});
    GenSubsetsIter({1, 2, 6, 90, 0});
}
