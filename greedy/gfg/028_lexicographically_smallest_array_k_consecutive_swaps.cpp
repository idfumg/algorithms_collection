#include "../../template.hpp"

vi LexicoSmallestAfterKSwaps(vi arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n and k > 0; ++i) {
        int to = i;
        for (int j = i; j <= i + k and j < n; ++j) {
            if (arr[to] > arr[j]) {
                to = j;
            }
        }
        k -= to - i;
        for (int from = i; from < to; ++from) {
            swap(arr[from], arr[to]);
        }
    }
    return arr;
}

int main() { TimeMeasure _;
    cout << LexicoSmallestAfterKSwaps({7,6,9,2,1}, 3) << '\n'; // 2,7,6,9,1
    cout << LexicoSmallestAfterKSwaps({7,6,9,2,1}, 1) << '\n'; // 6,7,9,2,1
}
