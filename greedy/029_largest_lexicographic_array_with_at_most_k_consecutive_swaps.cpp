#include "../template.hpp"

vi LexiLargestArrayWithKSwaps(vi arr, int k) {
    int n = arr.size();
    for (int i = 0; i < n - 1 and k > 0; ++i) {
        int pos = i;
        for (int j = i + 1; j < n and j - i <= k; ++j) {
            if (arr[pos] < arr[j]) {
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
    cout << LexiLargestArrayWithKSwaps({3,5,4,1,2}, 3) << '\n'; // 5,4,3,2,1
    cout << LexiLargestArrayWithKSwaps({3,5,1,2,1}, 3) << '\n'; // 5,3,2,1,1
}
