//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    cin >> k;

    int odds = 0;
    int evens = 0;

    for (int i = 1; i <= k; ++i) {
        if (i & 1) {
            ++odds;
        }
        else {
            ++evens;
        }
    }

    cout << odds * evens << '\n';
}
