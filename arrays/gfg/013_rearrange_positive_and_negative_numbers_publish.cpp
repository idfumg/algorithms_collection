#include "../../template.hpp"

void RearrangePositiveAndNegative(vi arr) {
    int n = arr.size();
    int pos = 0;
    int neg = n - 1;
    while (pos < neg) {
        if (arr[pos] < 0) {
            swap(arr[pos], arr[neg--]);
        }
        else {
            ++pos;
        }
    }
    for (pos = 1; pos < neg and neg < n; pos += 2, ++neg) {
        swap(arr[pos], arr[neg]);
    }
    debugn(arr);
}

int main() { TimeMeasure _;
    vi arr = {-1, 2, -3, 4, 5, 6, -7, 8, 9};

    RearrangePositiveAndNegative(arr);
}
