#include "../../template.hpp"

int CountPairsOfNaturalNumsWithGcd(int a, int b, int g) {
    int ans = 0;
    for (int i = a; i <= b; ++i) {
        for (int j = i; j <= b; ++j) {
            if (gcd(i, j) == g) {
                if (i != j) {
                    ans += 2;
                }
                else {
                    ++ans;
                }
            }
        }
    }
    return ans;
}

int main() { TimeMeasure _; __x();
    cout << CountPairsOfNaturalNumsWithGcd(1, 11, 5) << endl; // 3
    cout << CountPairsOfNaturalNumsWithGcd(1, 10, 7) << endl; // 1
}
