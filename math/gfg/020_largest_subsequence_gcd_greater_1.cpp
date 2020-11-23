#include "../../template.hpp"

int LargestGCDSubsequence(vi arr) {
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end());
    int ans = 0;
    for (int i = 2; i <= maxi; ++i) {
        int count = 0;
        for (int num : arr) {
            if (num % i == 0) {
                ++count;
            }
        }
        ans = max(ans, count);
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << LargestGCDSubsequence({3, 6, 2, 5, 4}) << endl; // 3
    cout << LargestGCDSubsequence({10, 15, 7, 25, 9, 35}) << endl; // 4
}
