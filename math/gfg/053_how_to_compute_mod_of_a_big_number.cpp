#include "../../template.hpp"

int ModOfHugeNumber(const string& s, int m) {
    int ans = 0;
    for (char ch : s) {
        ans = (ans * 10 + ch - '0') % m;
    }
    return ans;
}

int main() { TimeMeasure _;
    cout << ModOfHugeNumber("12316767678678", 10) << endl; // 8
}
