//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int ans = 0;
    int p = 0;
    while (n > 0) {
        int rem = n % 10;

        if (rem == 1) {
            rem = 9;
        }
        else if (rem == 9) {
            rem = 1;
        }

        ans += rem * pow(10, p++);

        n /= 10;
    }
    cout << ans << '\n';
}
