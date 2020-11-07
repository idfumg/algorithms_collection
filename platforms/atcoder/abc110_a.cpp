//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

int GetMaxAllowance(int a, int b, int c) {
    if (a < b) {
        swap(a, b);
    }
    if (a < c) {
        swap(a, c);
    }
    if (b < c) {
        swap(b, c);
    }
    return a * 10 + b + c;
}

int main() {
    int a;
    int b;
    int c;

    cin >> a;
    cin >> b;
    cin >> c;

    cout << GetMaxAllowance(a, b, c) << '\n';
}
