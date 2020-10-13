#include "../template.hpp"

void SubsetWithSumGreaterThanRemaining(vi arr) {
    int n = arr.size();
    if (n == 0) return;
    int total = accumulate(arr.begin(), arr.end(), 0) / 2;
    sort(arr);
    int count = 1;
    int sum = arr[n - 1];
    for (int i = n - 2; i >= 0 and sum <= total; --i) {
        sum += arr[i];
        ++count;
    }
    cout << count << '\n';
}

int main() { TimeMeasure _; __x();
    SubsetWithSumGreaterThanRemaining({3, 1, 7, 1});
    SubsetWithSumGreaterThanRemaining({2, 1, 2});
}
