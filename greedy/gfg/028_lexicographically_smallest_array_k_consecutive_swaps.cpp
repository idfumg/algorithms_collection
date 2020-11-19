#include "../../template.hpp"

vi LexicoSmallestAfterKSwaps(vi arr, int k) {
    int n = arr.size();
    int current = 0;
    while (k > 0) {
        int smallest = current;
        for (int i = smallest, j = i + k; i <= j; ++i) {
            if (arr[i] < arr[smallest]) {
                smallest = i;
            }
        }
        k -= smallest;
        for (; smallest > current; --smallest) {
            swap(arr[smallest], arr[smallest - 1]);
        }
        current++;
    }
    return arr;
}

int main() { TimeMeasure _;
    cout << LexicoSmallestAfterKSwaps({7,6,9,2,1}, 3) << '\n'; // 2,7,6,9,1
    cout << LexicoSmallestAfterKSwaps({7,6,9,2,1}, 1) << '\n'; // 6,7,9,2,1
}
