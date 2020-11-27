#include "../../template.hpp"

int WaysToFactorizionOfTwoFactors(int n) {
    int ans = 0;
    for (int i = 1; i * i < n; ++i) {
        if (n % i == 0) {
            ++ans;
        }
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << WaysToFactorizionOfTwoFactors(12) << endl; // 3
    cout << WaysToFactorizionOfTwoFactors(36) << endl;// 4
}
