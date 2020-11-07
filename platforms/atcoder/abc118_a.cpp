//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    int b;

    cin >> a;
    cin >> b;

    if (b % a == 0) {
        cout << b + a << '\n';
    }
    else {
        cout << b - a << '\n';
    }
}
