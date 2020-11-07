//#include "../../template.hpp"

#include <bits/stdc++.h>

using namespace std;

int main() {
    int a;
    int b;
    int c;

    cin >> a;
    cin >> b;
    cin >> c;

    if (a > b) swap(a, b);
    if (a > c) swap(a ,c);
    if (b > c) swap(b, c);

    cout << ((c - b) + (b - a)) << '\n';
}
