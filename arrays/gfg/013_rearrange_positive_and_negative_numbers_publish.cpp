#include "../../template.hpp"

void RearrangePositiveAndNegative(vi arr) {
    int n = arr.size();
    int pos = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] < 0) {
            swap(arr[i], arr[pos++]);
        }
    }
    for (int neg = 0; arr[neg] < 0 and pos < n and neg < pos; ++pos, neg += 2) {
        swap(arr[neg], arr[pos]);
    }
    cout << arr << '\n';
}

int main() { TimeMeasure _;
    vi arr = {-1, 2, -3, 4, 5, 6, -7, 8, 9};

    RearrangePositiveAndNegative(arr);
}
