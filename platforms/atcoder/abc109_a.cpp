//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

bool ThereIsAnInteger(int a, int b) {
    for (int c : {1, 2, 3}) {
        if (a * b * c & 1) {
            return true;
        }
    }
    return false;
}

int main() {
    int a;
    int b;

    cin >> a;
    cin >> b;

    if (ThereIsAnInteger(a, b)) {
        cout << "Yes" << '\n';
    }
    else {
        cout << "No" << '\n';
    }
}
