#include "../../template.hpp"

int LargestSubsetWithGcd1(vi arr) { // size <= 32
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int g = 0;
        int count = 0;
        for (int j = 0; j < n; ++j) {
            if (i & (1 << j)) {
                ++count;
                g = gcd(g, arr[j]);
            }
        }
        if (g == 1) {
            ans = max(ans, count);
        }
    }
    return ans;
}

int fast(vi arr) {
    int n = arr.size();
    int g = 0;
    for (int i = 0; i < n; ++i) {
        g = gcd(g, arr[i]);
        if (g == 1) {
            return n;
        }
    }
    return 0;
}

int main() { TimeMeasure _; __x();
    cout << LargestSubsetWithGcd1({2, 3, 5}) << endl; // 3 // O(n*logn*2^n)
    cout << LargestSubsetWithGcd1({3, 18, 12}) << endl; // 0
    cout << endl;
    cout << fast({2, 3, 5}) << endl; // 3 // O(n)
    cout << fast({3, 18, 12}) << endl; // 0
}
