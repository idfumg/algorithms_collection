#include "../../template.hpp"

void RandomShuffle(vi arr) {
    int n = arr.size();
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(arr[i], arr[j]);
    }
    debugn(arr);
}

int main() { TimeMeasure _;
    vi arr = {1, 2, 3, 4, 5, 6, 7, 8};
    RandomShuffle(arr);
}
