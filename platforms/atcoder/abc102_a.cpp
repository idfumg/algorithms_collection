//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

int GetMinPositiveDivisible(int n) {
    if (n % 2 == 0) {
        return n;
    }

    return 2 * n;
}

int main() {
    int n;
    cin >> n;

    cout << GetMinPositiveDivisible(n) << '\n';
}
