#include "../template.hpp"

vi LexicoSmallestAfterKSwaps(vi arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n - 1 and k > 0; ++i) {
        int pos = i;
        for (int j = i + 1; j < n and j - i <= k; ++j) {
            if (arr[pos] > arr[j]) {
                pos = j;
            }
        }
        for (int j = pos; j > i; --j) {
            swap(arr[j], arr[j - 1]);
        }
        k -= pos - i;
    }
    return arr;
}

int main() { TimeMeasure _;
    cout << LexicoSmallestAfterKSwaps({7,6,9,2,1}, 3) << '\n'; // 2,7,6,9,1
    cout << LexicoSmallestAfterKSwaps({7,6,9,2,1}, 1) << '\n'; // 6,7,9,2,1
}
