#include "../../template.hpp"

int FindDivisors(int n) {
    int ans = 0;
    for (int i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            ++ans;
        }
    }
    for (int i = n; i >= sqrt(n); --i) {
        if (n % i == 0) {
            ++ans;
        }
    }
    return ans;
}

int CountNumOfPairs(int n) {
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        int divisors = FindDivisors(i);
        ans += divisors;
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << CountNumOfPairs(2) << endl; // 3
    cout << CountNumOfPairs(3) << endl; // 5
}
