
#include "../../template.hpp"

int GCDWithALargeNumber(int a, string b) {
    int ans = 0;
    int n = b.size();
    for (int i = 0; i < n; ++i) {
        ans = (ans * 10 + b[i] - '0') % a;
    }
    return gcd(a, ans);
}

int main() { TimeMeasure _;
    cout << GCDWithALargeNumber(978, "89798763754892653453379597352537489494736") << endl; // 6
    cout << GCDWithALargeNumber(1221, "1234567891011121314151617181920212223242526272829") << endl; // 3
}
